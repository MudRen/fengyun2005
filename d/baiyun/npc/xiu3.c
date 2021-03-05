// weitianpeng.c
#include <ansi.h>

inherit SMART_NPC;

void create()
{
        set_name("孙秀青", ({ "sun xiuqin","sun" }) );
        set("gender", "女性" );
        set("title", "峨嵋派 侠女" );
        set("nickname", HIR"三英四秀之"NOR );
        set("long",
"风姿绰约，一把佩剑令她看上去愈发英气勃勃，不让须眉。\n"
                );
        set("attitude", "peaceful");
        set("age", 27);
        set("combat_exp", 200000);
        
        set("inquiry",  ([
                "叶孤城" : "叶城主的飞仙剑法想必有独步天下之处，师傅也很是佩服啊。\n",
                "master ye" : "叶城主的飞仙剑法想必有独步天下之处，师傅也很是佩服啊。\n",
                  "西门吹雪" :"唉，西门公子能否赢得了叶城主？这紫禁之战真让人挂怀。。\n",
                  "master ximen" :"唉，西门公子能否赢得了叶城主？这紫禁之战真让人挂怀。。\n",
        ])                      );
        set("chat_chance", 1);
        set("chat_msg", ({
                "孙秀青眉头微皱，轻轻理了理被海风吹散的长发。。\n",
                }) );

		set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	    	 (: auto_smart_fight(6) :),
     	}) ); 		

		auto_npc_setup("wang",80,60,0,"/obj/weapon/","fighter_w","diesword",1);               
        setup();

        carry_object(__DIR__"obj/emeisword3")->wield();
        carry_object("/d/fugui/npc/obj/w_skirt3")->wear();
}


