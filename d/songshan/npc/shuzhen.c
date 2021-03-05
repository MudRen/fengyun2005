// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
#include <ansi.h>
int kill_him();
void create()
{
        set_name("叶淑贞", ({ "ye shuzhen", "ye"}) );
        set("nickname", HIR "前任帮主夫人"NOR);
        set("gender", "女性" );
        set("age", 44);
		set("per", 55);
        set("int",30);
		set("attitude","friendly");
        set("long","叶淑贞是丐帮的前任帮主任慈的夫人，却不知为何在此。\n");
        set("combat_exp", 4000000);
        set("inquiry", ([
                "南宫灵" : (: kill_him :),
                "master nangong" : (: kill_him :),
                "任慈":		"任慈乃我夫君。\n",
                "黑珍珠":	"action叶淑贞满脸紧张，一语不发。\n",
        ]));
        setup();
        carry_object(__DIR__"obj/blackcloth")->wear();

}

int kill_him()
{
	command("say 南宫对我甚为孝顺，每天清粥一碗，从未间断！\n");
	return 1;
}

int accept_object(object who, object ob)
{
	if(ob->name() == "云素密函"){
        command("say 我写此信也是万不得以，南宫野心勃勃，篡夺丐帮帮主
之位，更将我囚禁于此，我已托人将此讯传于我夫，不知可曾送到。\n");
		return 0;
	}
    return 0;
}

