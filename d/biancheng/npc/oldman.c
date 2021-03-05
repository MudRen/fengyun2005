#include <ansi.h>
inherit SMART_NPC;
inherit INQUIRY_MSG;

int show_me();

void create()
{
    	set_name("看坟老人",({"oldman"}));
	set("long","
老人已经七十多岁了，身板依旧挺直。鬓发变白和稀疏了，露出宽阔而突起的
脑门。他的脸刻着深深的皱纹，每一道都是岁月的痕迹。\n");
     	
     	set("gender","男性");
    	set("attitude", "friendly");
    	set("group","citizen");
    	
    	set("combat_exp",4000000);  
    	set("age",72);
    	 	 	
		set("inquiry", ([
        	"驱鬼" : 	(: show_me :),
           	"鬼" :		 (: show_me :),
           	"坟地" :	 (: show_me :),
           	"ghost": 	 (: show_me :),
   		]));

    	set("nb_chat_chance", 100);
    	set("nb_chat_msg_combat", ([
    		10: name()+"道：“来人啊，强盗来盗墓啦！”\n",

        ]) );    	
    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	    	 (: auto_smart_fight(30) :),
        }) );
    	set("chat_chance",1);
    	set("chat_msg",({
		name()+"说：“如果有人能驱鬼就好了。”\n",
    	}) );    	    	
    	
    	
		auto_npc_setup("wang",200,170,0,"/obj/weapon/","fighter_w","healer",1);
	
		setup();
    	carry_object("/obj/armor/cloth")->wear();    
    	carry_object(__DIR__"obj/stick")->wield();
}


void init()
{	
	object ob;

	::init();
	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}

void greeting(object ob)
{
	object book;
	int count;
	
	if( !ob || environment(ob) != environment() ) return;
	if (ob->query("marks/wanma/zombie")>= ob->query("achieved_level")+40) {
		command("touch "+ob->get_id());
		command("say 太感谢了，这坟地应该能太平一阵了！");
		if (!REWARD_D->check_m_success(ob,"扫荡僵尸")) {
			REWARD_D->riddle_done(ob,"扫荡僵尸",50,1);
			ob->set("marks/e_wanma/扫荡僵尸",1);
			tell_object(ob,HIW"你在这个边远小镇的声誉上升了！\n"NOR);
		} 
		tell_object(ob,CYN"\n看坟老人掏出一本破旧的小册子说：这本东西是我在一个坟头捡到的，\n"
+ RANK_D->query_respect(ob)+"除魔卫道，说不定会有些用处。\n"NOR);
		ob->delete("marks/wanma/zombie");
		book = new(BOOKS"learn/spells_150");
		book->move(ob);
		return;
	}	
	if ( REWARD_D->check_m_success(ob,"扫荡僵尸")){
		command("greet "+ob->query("id"));
		return;
	}
	if (REWARD_D->riddle_check(ob,"扫荡僵尸")) {
		command("say 恶鬼尚未除尽，这位"+RANK_D->query_respect(ob)+"还得多加努力啊！");
		count = ob->query("achieved_level")+40;
		count = ob->query("marks/wanma/zombie")* 100 / count;
		tell_object(ob,"（你才完成了百分之"+chinese_number(count)+"耶！）\n");
		return;
	}		
	command("say 这位"+RANK_D->query_respect(ob)+"请止步，坟地有鬼，不太平啊。");
	return;	
}



int show_me()	{
	object me,ob;
	
	me=this_player();
	ob=this_object();
	if (REWARD_D->riddle_check(me,"扫荡僵尸")) {
		command("say 僵尸不除，这坟地不太平啊!");
		return 1;
	}
	
	if (REWARD_D->check_m_success(me,"扫荡僵尸")) {
		command("say 多亏你的帮助，现在镇上的人又敢来扫墓了。");
		return 1;
	}
	command("say 这坟地自半年前开始闹鬼，先是晚上有怪叫声，现在连白天也不太平了。");
	command("say 镇上的人都不敢去扫墓，也有几个胆大的结伙进去，这一去就没出来过。");
	command("shiver");
	command("say 前些天有个穿黑衣服的官爷不信邪闯了进去，现在还没有消息，看来凶多吉少。");
	command("say 你若能把这里面的恶鬼都驱个干净，咱们全镇老少都感激不尽。");
	command("say 万一陷在里面出不来了，找块坟头磕个头（kneel）就行了。");
	tell_object(me,"说罢，老人颤巍巍地走到一旁。 \n");
	REWARD_D->riddle_set(me,"扫荡僵尸",1);
	return 1;
}

