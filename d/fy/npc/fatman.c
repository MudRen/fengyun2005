// tea_waiter.c
#include <ansi.h>
inherit NPC;
inherit F_VENDOR;
int tell_him();
int stone();
void create()
{
        set_name("大胖子", ({ "big fatman","fatman" }) );
        set("gender", "男性" );
        set("age", 40);
        set("long",
                "一个白白胖胖的矮胖子，因为他太胖了，所以要整天洗澡。\n");
	set("combat_exp", 50000);
        set("chat_chance", 1);
        set("chat_msg", ({
                "大胖子指着你讥笑道：你．．你比我还胖还矮．．\n",
				"大胖子哼道：月圆之夜，紫禁之巅，叶城主赢定了．．\n",
        		"大胖子叹了口气：得失不由人，天意。。。\n",
				"大胖子神秘道：你可听说五彩灵石现世？\n",
		}) );

    	set("inquiry", ([
        	"sword" : (: tell_him :),
        	"宝剑" : (: tell_him:),
        	"stone" : (: stone :),
        	"五彩灵石" : (: stone :),
        	"丢了":	"丢了就是丢了，我怎么知道在哪儿，知道我还会没找到？\n",
        	"保健":	"action大胖子双臂举过头顶说：我可以当州长了！\n",	
        ]));

        set("attitude", "friendly");
        set("cps", 25);
        set("cor", 30);
        set("rank_info/respect", "胖哥");
        set("vendor_goods", ([
                __DIR__"obj/dogmed":10,
        ]) );
        setup();
        carry_object("/obj/armor/cloth")->wear();

}

void init(){
	add_action("do_vendor_list", "list");
	add_action("do_look", "look");

}

int stone(){
	object me;
	me = this_player();
	message_vision(YEL"\n$N遗憾地说道：“可惜具体我也不是很清楚，只听说是几块有灵力的石头。\n"NOR, this_object());
	message_vision(YEL"不过，前些日子有个怪里怪气的小孩子来打听过，也许他知道一些消息。”\n"NOR,this_object());
	return 1;	
}

int tell_him()
{
    object me;
    me =this_player();
	if (REWARD_D->riddle_check(me,"失剑风波")==2
		|| REWARD_D->riddle_check(me,"失剑风波")==3 ) {
		tell_object(me,"大胖子道：咳！本来以为捡了个大便宜，但肯定是老天爷看不顺眼，让我又丢了！\n");
		REWARD_D->riddle_set(me,"失剑风波",3);
		return 1;
	}
	message_vision("大胖子说：什么保健？老子身体好得很，用不着那个。\n", me);
	return 1;
}

int attack() {
	object opponent;
	
	opponent = select_opponent();
	if(objectp(opponent)) {
		set_temp("last_opponent", opponent);
        if(random(8)) {
		    COMBAT_D->fight(this_object(), opponent);
		} else {
		    message_vision("大胖子冲$N大喝：今天让你看看你家胖子哥的真正厉害！！\n", opponent);
		    message_vision("大胖子合身扑向$N，一时间$N眼前的空间被大胖子完全填满。\n", opponent);
		    message_vision("真是退不及退，闪无可闪。\n", opponent); 
            message_vision(HIW"\n“轰”的一声，大胖子结结实实地撞上$N\n$N被撞得象个扁扁的剪纸猫。\n"NOR, opponent);  
            opponent->unconcious();		    
		    message_vision("\n大胖子笑道：就凭你这样两斤半的三脚猫也来和我比试？ \n", this_object());
		    this_object()->remove_all_killer();
		}
		return 1;
	} else
		return 0;
}


int do_look(string arg) {
	
	string msg;
	object me, obj;
	me = this_player();
	obj = this_object();
	if (!arg || (arg != ((string) query("id")))) return 0;
	msg="一个白白胖胖的矮胖子，因为他太胖了，所以要整天洗澡。
他看起来约四十多岁。
他相貌平平。
他心宽体胖，武功看起来好象马马虎虎，出手似乎不重。\n";

	if(obj->query("max_kee")) {
		msg += "他" + COMBAT_D->eff_status_msg((int)obj->query("eff_kee") * 100 
				/ (int)obj->query("max_kee")) + "\n";
	}
	msg+="他身穿布衣(Cloth)\n";

	tell_object(me, msg);
	return 1;
}
void reset()
{
	set("vendor_goods", ([
    __DIR__"obj/dogmed":100,
        ]) );
}
