#include <ansi.h>
inherit SMART_NPC;
void create()
{
        set_name("刘仲甫", ({ "liu zhongpu","liu" }) );
        set("gender", "男性" );
        set("title","江南棋客");
        set("nickname",HIY"奉饶天下棋先"NOR);
        set("age", 42);
        set("long", "其时所向披靡的一代国手，相传在骊山与一乡下老媪对弈一百二十着，
被杀得大败，登时呕血数升。\n");
        set("combat_exp", 2500000);
        set("chat_chance", 1);
        set("chat_msg", ({
        	"刘仲甫愁眉不展，看了看手中棋谱，又摇了摇头，长叹了口气。\n",
        }) );
        set("attitude", "friendly");
		
		set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	    	 (: auto_smart_fight(20) :),
     	}) ); 		

		auto_npc_setup("wang",150,160,0,"/obj/weapon/","fighter_w","dragonstrike",1);
        setup();
        carry_object(AREA_RESORT"npc/obj/wqi");
        carry_object("/d/fugui/npc/obj/m_cloth2")->wear();
}


int accept_fight(object me)
{
        command("say 别。。老朽之人，何堪惊吓。\n");
        return 0;
}