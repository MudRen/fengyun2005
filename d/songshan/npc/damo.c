inherit NPC;
#include <ansi.h>
inherit F_MASTER;
void create()
{
    set_name("达摩面壁像", ({ "damo", "master", "print", "damo print" }) );
    set("gender", "男性");
    set("age", 999);
    set("long", "一个达摩面壁姿态的形象，衣褶折纹，隐约可见，宛如一幅淡色的水墨画像 。\n");
    set("attitude", "peaceful");
    set("reward_npc", 1);
    set("difficulty", 40);
    set("str", 6000);
    set("cor", 30);
    set("int", 24);
    set("cps", 30);
    set("force", 80000);
    set("max_force", 80000);
    set("force_factor", 1000);
    set("combat_exp", 10000000);
    set("score", 200000);

    set("class", "shaolin");

    set_skill("iron-cloth",160);	
    set_skill("dodge", 180);
    set_skill("force", 190);
    set_skill("unarmed", 180);
    set_skill("chanting", 200);

    set_skill("move", 160);
    set_skill("parry",160);
    set_skill("perception",100);
    set_skill("foreknowledge",100);

    set_skill("literate",100);
    set_skill("yijinjing", 200);
    set_skill("zen", 200);
    set_skill("xiaochengforce",150);

    set_skill("axe",200);
    set_skill("spear",200);
    set_skill("staff",200);
    set_skill("hammer",200);
    set_skill("blade",200);

    set_skill("dabei-strike",160);
    set_skill("puti-steps",160);
    set_skill("lianxin-blade",150);
    set_skill("wuche-axe",150);
    set_skill("duanhun-spear",150);
    set_skill("fumostaff",150);
    set_skill("liuxing-hammer",150);
    set_skill("yizhichan",170);

    map_skill("hammer","liuxing-hammer");
    map_skill("staff","fumostaff");
    map_skill("spear","duanhun-spear");
    map_skill("unarmed","yijinjing");
    map_skill("force","yijinjing");
    map_skill("iron-cloth","yijinjing");
    map_skill("dodge","puti-steps");
    map_skill("axe","wuche-axe");

    set("no_shown",1);
    set("rank_nogen",1);
    create_family("少林寺", 1, "达摩师祖");
    set("rank_levels",({ 16000, 32000,64000, 128000,
	256000,512000,1024000,1536000,2048000,
	3064000,4096000, 5120000,6144000,8192000,
	9999999}));
    set("ranks",({"沙弥","僧人","罗汉","金刚","上人","高僧","大师",
	"长老","法堂长老","戒律院长老","法堂首座","戒律院首座",
	YEL"长老院首座"NOR,YEL"副主持"NOR,YEL"禅宗传人"NOR,HIY"禅宗宗主"NOR}));
    setup();
}
int accept_fight(object me){
    return 0;
}
void attempt_apprentice(object me)
{
    if(me->query("class")=="shaolin"
      && REWARD_D->check_m_success(me,"少林面壁"))
	//		&& me->query("marks/少林_面壁成功"))
	command("recruit " + me->query("id") );
}

void recruit_apprentice(object ob){
    if( ::recruit_apprentice(ob) )
	ob->set("class", "shaolin");
}

void init(){
    add_action("do_look","look");
}

int do_look(string arg){
    object me;
    me = this_player();
    if (arg == "print" || arg == "damo" || arg =="master" || arg == "damo print"){
	if (REWARD_D->check_m_success(me,"少林面壁")) {
	    //		if(me->query("marks/少林_面壁成功")) {
	    message("vision", me->name() + "若有所思的盯着面前的石壁。\n", environment(me), me);
	    tell_object(me, CYN"一个达摩面壁姿态的形象，衣褶折纹，隐约可见，宛如一幅淡色的水墨画像。\n"NOR);
	    return 1;
	} else {
	    tell_object(me, "灰蒙蒙的一片石壁，你什么也看不出来。\n");
	    return 1;
	}
    }
    return 0;
}

