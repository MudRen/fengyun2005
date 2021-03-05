// suan.c

#include <ansi.h>

inherit NPC;

void create()
{
        set_name("酸梅汤", ({ "suanmei tang","tang" }) );
        set("gender", "女性" );
//		set("vendetta_mark","fugui");
        set("age", 24);
        set("no_arrest",1);
        set("long",
"酸梅汤非但漂亮，而且漂亮极了。她身上穿的虽然是件粗布衣服，但无
论什么衣服穿在她身上，都会变得很好看。\n\n");

        set("combat_exp", 500000);
        set("attitude", "friendly");
                
        set_skill("sword", 100);
        set_skill("move", 100);
        set_skill("snowshade-sword", 120);
        set_skill("force", 100);
		set_skill("notracesnow",100);
		set_skill("dodge",120);
		set_skill("parry",120);
		set_skill("gouyee",100);
        map_skill("sword", "snowshade-sword");
        map_skill("parry", "snowshade-sword");
        map_skill("dodge", "notracesnow");
        map_skill("move", "notracesnow");
        map_skill("force", "gouyee");
        
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: perform_action, "sword.baixueaiai" :),
        }) );
	
		set("chat_chance",2);
        set("chat_msg", ({
        "酸梅汤似乎在四处寻找着些什么，喃喃自语道：“奇怪，前些日子我\n明明把那几箱财宝藏在这柴房的呀。”\n\n",
                                })  );
        setup();
        carry_object("/obj/armor/cloth")->wear();
	carry_object("/obj/weapon/sword")->wield();
}

void init()
{
        object  ob;
        ::init();
        ob = this_player();
		call_out("greeting", 1, ob);       
}


int greeting(object ob)
{
	if (!ob || environment(ob)!= environment(this_object()))	return 1;
		
	message_vision("$N皱着眉头，用袖子挡着脸埋怨道：“这柴房也实在脏到家了，
哦，麻烦这位"+RANK_D->query_respect(ob)+"帮我打扫一下,好么？”\n",this_object());
	return 1;
}