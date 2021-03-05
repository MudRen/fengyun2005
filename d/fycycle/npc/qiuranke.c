inherit NPC;
#include <ansi.h>
int regive_book();
void create()
{
        set_name("虬髯大汉", ({ "qiuran han","han" }) );
        set("gender", "男性" );
        set("long", "
一个腰粗膀阔，魁梧异常的虬髯大汉，身穿一套粗布棉袄，衣裤上都打了补钉。
看上去有些落魄，但举手投足之间不自禁流露出盖世英雄的气概！\n");

        set("class", "shaolin" );

        set("age", 51);
        set("no_arrest", 1);       
        set("combat_exp", 20000000);
        set("attitude", "friendly");
        set("toughness", 500);
        
        set_temp("apply/attack", 300);
        set_temp("apply/damage", 200);
        
        
        set("chat_chance", 2);
        set("chat_msg", ({
    		"虬髯大汉作了一个四方揖，朗声说道：在下河南人氏。路经贵地，一不求名，
二不为利，只为小女年已及笄，尚未许得婆家，因此斗胆比武招亲。\n",
    		"虬髯大汉说：丢了风尘简？这就太糟了！！\n",
                }) );
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: perform_action, "unarmed.luori" :),
                (: perform_action, "dodge.luoyeqiufeng" :),
        }) );
		set("inquiry", ([
                "丢了风尘简" : (: regive_book :),
                "丢失风尘简" : (: regive_book :),
                "风尘简" : (: regive_book :),
                "lost fengchen book" : (: regive_book :),
        ]));
                
        
        set_skill("yijinjing", 200);
        set_skill("fall-steps", 200);
        set_skill("force", 300);
        set_skill("unarmed", 300);
        set_skill("iron-cloth", 300);
        set_skill("parry", 300);
        set_skill("dodge", 300);
        set_skill("move", 300);
        set_skill("luoriquan", 300);
        
        map_skill("unarmed","luoriquan");
        map_skill("force","yijinjing");
		map_skill("iron-cloth","yijinjing");
      	map_skill("dodge","fall-steps");
	
        setup();
        carry_object("/obj/armor/cloth")->wear();
}

int accept_fight(object me)
{
        command("say 老朽技艺未精，怎是这位大侠敌手？\n");
        return 0;
}

int regive_book()
{
	object item,me;
	int copies;
	me = this_player();
	if (me->query("m_success/戏风尘")&& me->query("marks/风尘简"))
	{
		copies = me->query("m_success/戏风尘");
		if (copies > 3)
		{
			message_vision("$N对$n怒道：我已三番四次的赠书于你，既然你不知珍惜，又何必再问。\n",this_object(),me);
			return 1;
		}
		me->set("m_success/戏风尘",copies+1);
		item = new(BOOKS"f-"+ me->query("marks/风尘简"));
		if (item->move(me))		
			message_vision("$N递给$n一册竹简道：此乃我心血所著，好好收藏，切勿再丢!\n",this_object(),me);
		else 
		{
			message_vision("$N道：你身上废物太多，浪费了一次机会啊!\n",this_object(),me);	
			destruct(item);
		}
	}else
	{
		message_vision("$N望着$n冷笑道：做人要以诚为本，我生平最恨欺诈之徒。你好大的胆，竟敢欺骗于我。\n",this_object(),me);
	}
	return 1;

}

void zhaoqin(object me){
	object hong, mask;
	string gender;
	
	mask = present("skinmask", me);
	if (objectp(mask) && mask->query("equipped")) 
		gender = mask->query("fakegender");
		
	if(me->query("gender") != "男性" && gender != "男性"  ){
		message_vision("$N苦笑道：这个。。这位女侠情意俺替小女答谢了。\n", this_object());
	} else if (me->query("age") >= 30){
		message_vision("$N微怒道：阁下一把年纪，难道要我女儿守活寡么？（<30岁）\n", this_object());
	} else if (F_LEVEL->get_level(me->query("combat_exp")) < 14){
		message_vision("$N拱手道：恕俺直言，阁下才学未精，拳脚无眼，还是请回吧（需14级）\n", this_object());
	} else if ( REWARD_D->check_m_success(me,"戏风尘")){
		message_vision("$N哼声道：人贵知足，岂能妄求？\n", this_object());
	} else {
		
		hong = present("redcloth girl", environment(this_object()));
		message_vision("$N捋了捋胡须，朗声笑道：好！就让小女陪阁下过几招吧！\n", this_object());
		me->set_temp("marks/fight_hongfunv", 1);
	}
	return;
}

void lose_fight(object obj){
	object red, item;
//	int i;
	string *book = ({"iron-cloth",
			"spells",
			"magic",
			"move",
			"unarmed",
			"foreknowledge"
			});
	int n = random(6);
	
	red = present("redcloth girl", environment(this_object()));
	message_vision("$N哈哈大笑道：好！好！李靖诚不欺我！乱世艰难，沧海横流，当有英雄辈出！\n", this_object());
	message_vision("$N也爽朗地笑道：大哥，你可赌输了，别抵赖呦！\n", red);
	message_vision("$N点了点头。\n", this_object());	 
	message_vision(CYN"\n$N掏出一册竹简，郑重肃然地交给了$n。\n"NOR, this_object(),obj);
	message_vision("\n$N负手望天，叹道：苍狗白云，世事沧桑。想我虬髯客远赴天涯三十年，\n", this_object());
	message_vision("这乱世红尘也该是少年英雄们的天下了。也罢，这一册竹简乃是我游历海内诸国所著，\n", this_object());
	message_vision("当赠于这位少年英雄！\n", this_object());   
	message_vision("$N毕恭毕敬收起风尘简。\n", obj); 
	
	REWARD_D->riddle_done( obj, "戏风尘", 50, 1);
	
	item = new(BOOKS"f-"+ book[n]);
	item->move(obj);
	obj->set("marks/风尘简",book[n]);
	message_vision(HIG"\n$N仰天笑道：三妹，这一遭游戏红尘，不旺此生啊！走罢！\n"NOR, this_object()); 
	message_vision(HIG"$N轻轻携起红裳女子之手，飘然而去。\n"NOR, this_object());
	environment(this_object())->remove_flag();
//	-- DO NOT destroy object in lose_enemy(), it will create bugs in pfms which point to 
//		target after win-lose check !!!!
//	destruct(red);				
//	destruct(this_object()); 
	red ->set("leaving",1);
	red ->move(VOID_OB);
	this_object()->move(VOID_OB);
	call_out("leaving",2, red, this_object());
	
}

void win_fight(object obj){
	message_vision("$N拍了拍$n的肩膀，哈哈大笑：后生可畏，前途无量，别气馁别气馁！\n", this_object(), obj); 
	obj->set("marks/戏风尘", 1);
	return;
}


void leaving (object red, object qiuranke){
	if (red) destruct(red);
	if (qiuranke) destruct(qiuranke);
	return;
}