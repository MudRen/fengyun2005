inherit F_MASTER;
inherit SMART_NPC;

#include <ansi.h>
int leave();
int smart_fight();
int task1();

void create()
{
    	set_name("铁少", ({ "master tieshao", "master","tieshao" }) );
    	set("gender", "男性" );
    	set("nickname", HIG "多情刀客"NOR);
    	set("long","
铁少从十五岁开始就和爱妻雪蕊儿行侠江湖，刀剑合壁，天下无敌。
正当两人名声鼎盛之时，忽然退出江湖，隐居于此。\n");

    	set("marry","master xuerui");
    	set("group","legend");
 		set("couple","tiexue");	
    	set("boss", 1);
    	set("age", 25);
    	set("combat_exp", 20000000);
    	set("score", 90000);
    	set("reward_npc", 1);
    	set("difficulty", 40);
    	set("fly_target",1);
    		
    	set("class","legend");	
    	set("apprentice_available", 50);
    	create_family("铁雪山庄", 1, "庄主");
    	set("rank_nogen",1);
    	set("rank_levels",({ 16000, 32000,64000, 128000,
					256000,512000,1024000,1536000,2048000,
					3064000,4096000, 5120000,6144000,8192000,
					9999999}));
    	set("ranks",({"顽童","茶童","棋童","小侠","少侠","大侠",
    		"豪侠","奇侠","狂侠","情侠","侠圣","侠王",WHT"隐侠"NOR,
    		WHT"侠隐"NOR,WHT"气宗传人"NOR,HIW"气宗宗主"NOR}));
    	
   		set("inquiry", ([    	
        	"恒河三佛":	(: task1 :),
        	"考验":		(: task1 :),	
        	"leave" : (: leave :),
    		]));
    
    
    	set_temp("pfm/qidaoforce_juqi",200+random(200));
    	
    	set_skill("force", 200);
    	set_skill("chanting", 180);
    	set_skill("parry", 170);
    	set_skill("dodge", 170);
    	
    	set_skill("perception", 150);
    	set_skill("move",150);
    	set_skill("unarmed", 160);
    	set_skill("blade", 250);
    	set_skill("literate", 100);
    	set_skill("foreknowledge",100);    	
    	set_skill("meihua-shou", 150);
    	set_skill("qidaoforce", 150);
    	set_skill("fall-steps", 150);
    	set_skill("dormancy",300);
    	set_skill("six-sense",300);
    	set_skill("shortsong-blade", 200);
    	

    	map_skill("unarmed", "qidaoforce");
    	map_skill("blade", "shortsong-blade");
    	map_skill("force", "qidaoforce");
    	map_skill("parry", "shortsong-blade");
    	map_skill("dodge", "fall-steps");

     	set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: smart_fight() :),
	}) );

    	setup();
    	carry_object(__DIR__"obj/whitecloth")->wear();
    	carry_object(__DIR__"obj/mblade")->wield();
}


void reset()
{
    	set("apprentice_available", 20);
}


void attempt_apprentice(object ob)
{
    	if( query("apprentice_available") ) {
        if( find_call_out("do_recruit") != -1 )
            	command("say 慢著，一个一个来。");
        else
            	call_out("do_recruit", 2, ob);
    	} else {
        	command("say 本庄主今天已经收了二十个弟子，不想再收徒了。");
    	}
}


void do_recruit(object ob)
{
    	if( (string)ob->query("gender") != "男性" )
    	{      	
    		command("say 我只收男弟子，你还是去拜我的内人吧！");
    	}
    	else 
    	{
        	command("smile");
        	command("say 你日后必有大成！");
        	command("pat "+ ob->query("id"));
        	command("recruit " + ob->query("id") );
    	}
}


int recruit_apprentice(object ob)
{
    		if( ::recruit_apprentice(ob) )
        		ob->set("class", "legend");
    		add("apprentice_availavble", -1);
}


int accept_fight(object me)
{
    	object xiaocui;
    	if( objectp(xiaocui = present("cui", environment(this_object()))) && living(xiaocui))
    	{	
        	command("smile");
        	command("say 还是让小翠来吧。");
        	return 0;
    	}
    	else
        	command("sigh");
    		command("铁少慢慢的从翠竹凳上站起来，放下了手中的紫砂杯。");
    		command("say 请！");
    		call_out("do_unwie", 3);
    		return 1;
}


int do_unwie()
{
    	if( !this_object()->is_fighting())
    	{
        	message_vision("$N拿起茶杯浅啖一口，含情脉脉的望了雪蕊儿一眼，又坐在竹凳上。\n", this_object());
        	command("smile");
        	return 1;
    	}
    	else
        	call_out("do_unwie", 3);
}

void init()
{	
//	object me;
	add_action("do_killing", "kill");
    	::init();
 
}

int task1() {
	
	object me = this_player();
	
	if ( me->query("class")!= "legend") {
		command("say 铁雪门之事，与外人无关。");
		return 1;
	}
	
	if ( me->query_skill("six-sense",1) < 150)	{
		command("say 你学艺未成，切忌分心旁骛。");
		tell_object(me, WHT"（接受此考验需150级六灵暗识）\n"NOR);
		return 1;
	}
	
	if (REWARD_D->check_m_success( me, "力斗三佛")) {
		command("say 好孩子，你已经通过了这个考验。");
		return 1;
	}
	
	if (REWARD_D->riddle_check(me,"力斗三佛") == 1) {
		command("say 快去快去，为师静候佳音。");
		return 1;
	}
	
	command("say 数日前小翠路过嵩山，见几个番僧在山下挑衅，还打伤了几个少林门人。
据说这几个僧人号称『恒河三佛』，很是嚣张。你且代为师走一趟，把他们"YEL"赶回西
域"CYN"，也叫他们从此不敢再小看中原武林！\n"NOR);
    
    REWARD_D->riddle_set(me,"力斗三佛",1);	
    return 1;
}


int leave() {
	if (this_player()->query("class")!="legend") return 0;
	message_vision(CYN"$N道：人各有志，我不勉强你留下。\n"NOR, this_object(),this_player());
	message_vision(CYN"$N说：只是聚气心法非弟子不能使用，短歌刀法的精髓你大概也体会不到了。\n"NOR,this_object(),this_player());
	return 1;
}

int smart_fight(){
	object *enemy/*, me*/, ob;
	int i;	
	ob = this_object(); 
	enemy = ob->query_enemy();
	for (i=0;i<sizeof(enemy);i++){
		if (userp(enemy[i])) {
			switch (random(3)) {
				case 0: ccommand("perform dodge.luoyeqiufeng "+ enemy[i]->get_id()); break;
				case 1: ccommand("perform duangechangmeng "+ enemy[i]->get_id()); break;
				case 2: ccommand("perform duangechangmeng "+ enemy[i]->get_id()); break;
			}
			break;
		}
	}
	return 1;
	
}	
	
	