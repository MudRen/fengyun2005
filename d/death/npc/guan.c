// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
#include <ansi.h>
void create()
{
        set_name("关二爷", ({ "master guan", "master" }) );
        set("gender", "男性" );
        set("title", "武圣" );
        set("nickname", HIC"千里走单骑"NOR );
        set("age", 44);
        set("cor", 40);
        	
		set("attitude","friendly");
        set("long","上马金，下马银，不能改其义，千里送嫂，过五关斩六将的关二爷。\n");
        
        
		set("inquiry", ([
       		"明烟草" : 	"明烟乃我大嫂的闺名，怎能随便乱叫！\n",
    	]) );
        set("combat_exp", 2000000);
		set("no_busy",4);

        set_skill("move", 170);
        set_skill("parry", 160);
        set_skill("dodge", 160);
        set_skill("force", 160);
        set_skill("blade",150);
        set_skill("shortsong-blade",120);
        set_skill("qidaoforce",120);
        set_skill("fall-steps",250);
        
        map_skill("parry","shortsong-blade");
        map_skill("blade","shortsong-blade");
        map_skill("dodge","fall-steps");
        map_skill("move","fall-steps");
        
        setup();
    	carry_object(__DIR__"obj/g_blade")->wield();
        carry_object("/obj/armor/ghost_cloth")->wear();
}


int is_ghost() { return 1; }
