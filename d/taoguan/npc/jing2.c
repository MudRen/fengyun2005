inherit SMART_NPC;

void create()
{
        set_name("清漪师太", ({ "qingyi" }) );
        set("gender", "女性");
        set("title","三清宫  第六代弟子");
        set("age", 42);
        set("long","清漪原是丁白云出家前的贴身丫环，已跟随丁白云多年了。\n");
        set("combat_exp", 6400000);
        set("score", 200);
        set("class", "taoist");
		set("altitude","friendly");
        set("inquiry", ([
                "谷衣心法": "谷衣心法是我茅山派为对抗邪魔外道所创的内功心法。\n",
        ]) );
        set("fy41/sq_bolt_1",1);

        set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     (: auto_smart_fight(50) :),
        }) );
    	
		auto_npc_setup("wang",200,200,0,"/obj/weapon/","fighter_w","necromancy",1);
        setup();    
		carry_object(__DIR__"obj/s_skirt")->wear();
}


