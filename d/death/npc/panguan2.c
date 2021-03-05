inherit NPC;
#include <ansi.h>
void create()
{
        set_name("生死判官", ({ "death-judge" }) );
        set("long",
                "阎王身边的生死判官，掌管生死簿册。\n");
        set("age", 3100);
        set("cor", 37);
	set("str",100);
        set("combat_exp", 2000000);
	set_skill("move",200);
        set("attitude", "peaceful");
        set_temp("apply/attack", 80);
        set_temp("apply/parry", 80);
        set("chat_chance", 1);
        set("chat_msg", ({
		"生死判官看了你一眼，又在生死簿上钩了一下。\n",
		"生死判官说道：＂阎王爷，您看是扒他的皮还是抽他的筋？＂\n",
		"生死判官说道：＂阎王爷，您看他死前奸淫无道，现在让他投胎做妓女吧！\n",
		"生死判官说道：＂阎王爷，让他投胎做太监吧！\n",
		"生死判官问你：＂为什么见了阎王爷都不下跪？＂\n",
		"生死判官用他那空洞的眼睛望了望你的身后。\n",
		"生死判官哼了声：＂又来了一个。＂\n",

        }) );
        set_temp("apply/armor", 70);
        set_temp("apply/damage", 130);
        set_temp("apply/dodge", 70);
        set("inquiry", ([
		"投胎" : "排好队，慢慢来。\n",
                "*" : "你的废话真够多的！人都死了，嘴还不肯闭上。\n",
        ]) );
        setup();
        carry_object("/obj/armor/ghost_cloth")->wear();
}

void unconcious()
{
return;
}
void die()
{
return;
}

void init()
{
	::init();
        if( !previous_object()
        ||      !userp(previous_object()) )
                return;
        call_out( "death_stage", 1, previous_object() );
}


void death_stage(object ob)
{
        if( !ob || !present(ob) ) return;

        if( !ob->is_ghost() ) {
                command("say 哦？活人？活人也得变死人！");
                kill_ob(ob);
                ob->fight_ob(this_object());
                return;
}
}
