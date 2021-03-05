// orange.c
#include <ansi.h>
inherit NPC;
void create()
{       
        object armor;
        set_name(HIY"橙衣宫女"NOR, ({ "orange lady","lady" }) );
        set("nickname",WHT"气若游丝"NOR);
        set("long", "她身穿轻纱柔丝，白足如霜，青丝飘扬。\n");
        set("age", 26);
        set("gender", "女性");
        set("attitude", "peaceful");
        set("combat_exp", 4400000);  
        set_skill("force", 180);
        set_skill("unarmed", 200);
        set_skill("dodge", 200);
	set_skill("parry",200);
	set_skill("move", 200);
	set_skill("lingxi-zhi",161);
	set_skill("tie-steps",180);
	set_skill("perception",220);
	
	map_skill("unarmed","lingxi-zhi");
	map_skill("dodge","tie-steps");
	map_skill("move","tie-steps");

        setup();
        armor=new(__DIR__"obj/corclot");
	armor->set_name(HIY"橙丝衣"NOR,({"orange cloth","cloth"}) );
	armor->move(this_object());
	armor->wear();
	armor=new(__DIR__"obj/corclasp");
	armor->set_name(HIY"橙丝镯"NOR,({"orange bangle","bangle"}) );
	armor->move(this_object());
	armor->wear();	
	armor=new(__DIR__"obj/corgirt");
	armor->set_name(HIY"橙丝带"NOR,({"orange belt","belt"}) );
	armor->move(this_object());
	armor->wear();
	armor=new(__DIR__"obj/corhat");
	armor->set_name(HIY"橙丝帽"NOR,({"orange hat","hat"}) );
	armor->move(this_object());
	armor->wear();
	armor=new(__DIR__"obj/corboot");
	armor->set_name(HIY"橙丝鞋"NOR,({"orange boot","boot"}) );
	armor->move(this_object());
	armor->wear();
	armor=new(__DIR__"obj/corribb");
	armor->set_name(HIY"橙丝巾"NOR,({"orange ribbon","ribbon"}) );
	armor->move(this_object());
	armor->wear();
}

