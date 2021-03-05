// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;

#include <ansi.h>
int init_quest();

void create()
{
    set_name("戴寅", ({ "dai yin","dai"}) );
    set("title", "丐帮五袋弟子");
    set("gender", "男性" );
    set("age", 34);
    set("attitude","friendly");
    set("class","beggar");
    set("chat_chance_combat", 20);
    set("chat_msg_combat", ({
	(: perform_action, "unarmed.xianglongwuhui" :)
      }) );
      
     set("inquiry", ([
        "瞒天过海":	(: init_quest :),
        "商量":		(: init_quest :),
     	"袁姬":		"袁姬和清波公子真是苦命啊！\n",
     	"麻沸散":	"天机不可泄漏，速速去办了此事。\n",
     	"骗局":		"咳，这世上本来就是你骗我我骗你，不过，咱们丐帮是正义之师，
那叫斗智不斗力。\n",
		"中药店老板":	"那是我远房叔叔。\n",
     ]));  
      
    set("combat_exp", 250000);
    set_skill("move", 100);
    set_skill("parry",100);
    set_skill("dodge", 100);
    set_skill("force", 100);
    set_skill("literate", 80);
    set_skill("unarmed",100);
    set_skill("doggiesteps",80);
    set_skill("dragonstrike",80);
    set_skill("huntunforce",80);
    set_skill("begging",120);
    map_skill("dodge", "doggiesteps");
    map_skill("force", "huntunforce");
    map_skill("unarmed", "dragonstrike");
    setup();
    carry_object(__DIR__"obj/5bagcloth")->wear();

}

int	init_quest(){
	object me= this_player();
	
	if (REWARD_D->riddle_check(me,"魂断鹊桥")!= 7
		&& REWARD_D->riddle_check(me,"魂断鹊桥")!= 8)
		return 0;
		
	tell_object(me,CYN"
戴寅悄悄地说：此事只可智取，不可力夺。

戴寅说：小人有一叔父，是此地药房老板，我曾听他说起『麻沸散』一药，
吃下去后立刻就死，可是过了三天还能复活。若是让袁姬服了此药，当能
骗过宫中之人，伺机将她救出！\n"NOR);
	REWARD_D->riddle_set(me,"魂断鹊桥",8);
	
	return 1;
}

