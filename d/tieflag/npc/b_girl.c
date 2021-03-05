// blue.c
#include <ansi.h>
inherit NPC;
void create()
{       
        object armor;
        set_name(BLU"蓝衣宫女"NOR, ({ "blue lady","lady" }) );
        set("nickname",WHT"身似浮云"NOR);
        set("long", "她身穿轻纱柔丝，白足如霜，青丝飘扬。\n");
        set("age", 26);
        set("gender", "女性");
        set("attitude", "peaceful");
        set("combat_exp", 4400000);  
	   
        set_skill("force", 180);
        set_skill("unarmed", 200);
        set_skill("dodge", 150);
	set_skill("parry",200);
	set_skill("move", 200);
	set_skill("lingxi-zhi",161);
	set_skill("tie-steps",150);
	set_skill("perception",220);
	
	
	map_skill("unarmed","lingxi-zhi");
	map_skill("dodge","tie-steps");
	map_skill("move","tie-steps");

        setup();
        armor=new(__DIR__"obj/corclot");
	armor->set_name(BLU"蓝丝衣"NOR,({"blue cloth","cloth"}) );
	armor->move(this_object());
	armor->wear();
	armor=new(__DIR__"obj/corclasp");
	armor->set_name(BLU"蓝丝镯"NOR,({"blue bangle","bangle"}) );
	armor->move(this_object());
	armor->wear();	
	armor=new(__DIR__"obj/corgirt");
	armor->set_name(BLU"蓝丝带"NOR,({"blue belt","belt"}) );
	armor->move(this_object());
	armor->wear();
	armor=new(__DIR__"obj/corhat");
	armor->set_name(BLU"蓝丝帽"NOR,({"blue hat","hat"}) );
	armor->move(this_object());
	armor->wear();
	armor=new(__DIR__"obj/corboot");
	armor->set_name(BLU"蓝丝鞋"NOR,({"blue boot","boot"}) );
	armor->move(this_object());
	armor->wear();
	armor=new(__DIR__"obj/corribb");
	armor->set_name(BLU"蓝丝巾"NOR,({"blue ribbon","ribbon"}) );
	armor->move(this_object());
	armor->wear();
}

