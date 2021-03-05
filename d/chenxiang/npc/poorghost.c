// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
#include <ansi.h>
int tell_him();
void create()
{
    	set_name("谷慧儿", ({ "gu huier", "huier" }) );
    	set("gender", "女性" );
    	set("age", 24);
    	set("attitude","friendly");
        set("long", "
谷慧儿生前在沉香镇上善跳花鼓，可惜在祭河神的时候失足落入水中，
急着去救的人们只来得及扯断她的一缕头发，尸体却被水冲走了，再
也没能找到。\n");
    	
    	set("combat_exp", 15000);
    	set("inquiry", ([
			"舅爷":		"我死去的舅爷掌管这里的城隍庙，他有个印，可以制服恶鬼！\n",
			"城隍庙":	"出门向北就是城隍庙了！\n",	
			"恩人":		"如果你能把恶鬼杀了，你就是我的恩人！\n",
			"大恩人":	"如果你能把恶鬼杀了，你就是我的恩人！\n",
			"头发":		"action谷慧儿看着手里的一缕断发，怔怔出神。\n",
			"hair":		"action谷慧儿看着手里的一缕断发，怔怔出神。\n",	
        	]));
    	setup();
    	carry_object("/obj/armor/cloth")->wear();
}


int is_ghost() { return 1; }


void init()
{
    	object ob;
    	::init();
    	if( interactive(ob=this_player()) && ob->visible(this_object()))
    	{
        	remove_call_out("greeting");
        	call_out("greeting", 1, ob);
    	}
}

void greeting(object ob)
{
    	if (!ob || environment(ob)!= environment())	return;
    		
    	tell_object(ob,"谷慧儿道：帮帮我吧，最近恶鬼一到晚上就出来，\n");
    	tell_object(ob,"你知不知道我死去的舅爷掌管这里的城隍庙，他有个印，可以制服恶鬼！\n"); 
    	ob->set_temp("marks/huier",1);
}


int accept_object(object me, object obj)
{
    	object hair;
    	
    	if(obj->query("huier")) {
        	command("say 这回我可以制服恶鬼了！\n");
        	command("say 真不知道怎么谢你，这缕头发是我死后唯一留下的东西。");
        	command("say 就送给你做个纪念吧。");
        	
        	hair = new(__DIR__"obj/hair");
        	if (!hair->move(me))
        		hair->move(environment());	       	
        	return 1;
    	}
    	return 0;
}

