inherit NPC;

void create()
{
        set_name("扫阶的道士", ({ "taoist" }) );
        set("gender", "男性");
        set("age", 19);
        set("long","三清宫的道士，着一身黑色的道袍，拿着扫把有气无力地扫着山路。\n");
        set("combat_exp", 10000);
        set("score", 200);
        set("class", "taoist");
        set("mana", 300);
        set("max_mana", 300);
        set("mana_factor", 5);

        set("inquiry", ([
                "谷衣心法": "谷衣心法是我茅山派为对抗邪魔外道所创的内功心法。\n",
                "三清宫": "三清宫就在山上，不过师傅们见不见你就看你的造化了。\n",
        ]) );
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: cast_spell, "netherbolt" :),
        }) );

        set("chat_chance", 2);
        set("chat_msg", ({
                name()+"悻悻地说道：“练丹，练丹，练出这么多怪物来！”\n",
                name()+"说：“师傅们今天都在山上，想拜师就快上山吧。”\n"
        }) );

//        create_family("三清宫", 7, "弟子");

        set_skill("magic", 20);
        set_skill("move", 20);
        set_skill("force", 20);
        set_skill("spells", 30);
        set_skill("unarmed", 40);
        set_skill("sword", 40);
        set_skill("parry", 50);
        set_skill("dodge", 30);
        set_skill("gouyee", 50);
        set_skill("taoism", 30);
        set_skill("necromancy", 30); 
        set_skill("snowshade-sword",30);
        set_skill("notracesnow",30);
        
        map_skill("dodge","notracesnow");   
	map_skill("force", "gouyee");
        map_skill("spells", "necromancy");
        map_skill("parry","snowshade-sword");
        map_skill("sword","snowshade-sword");
                
        setup();

        carry_object(__DIR__"obj/sword1")->wield();
	carry_object(__DIR__"obj/tcloth")->wear();
}
