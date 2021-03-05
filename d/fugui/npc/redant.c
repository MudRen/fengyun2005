#include <ansi.h>
inherit NPC;
void create()
{
        set_name(HIR"红蚂蚁"NOR, ({ "red ant", "ant" }) );
        set("long","
她穿着件紧身的红衣服，该细的地方绝不粗，该胖的地方绝不瘦，一
张端端正正的瓜子脸，眉似远山，目如春水，笑面甜甜的，更浓的化
不开，只要将她再放大一倍，就是个绝色的美人。\n");
        set("chat_chance",2);
		set("chat_msg",	({
		"红蚂蚁咬着嘴唇，皱了皱眉道：”这穷山僻壤，怎么连些胭脂花粉都\n没有，这灰头灰脸的样子实在没法见人呀。”\n",
		"红蚂蚁眉目流盼，自言自语道：“听说极品绍兴女儿红能够养颜，我应该试试。”\n"
		})  );

		set("gender","女性");
		set("age",22);
	        set("combat_exp", 300000);
	
		set("int",30);
		set("cor",30);
		
		set_skill("throwing",200);
		set_skill("feidao",100);
		set_skill("dodge",150);
		set_skill("move",150);
		map_skill("throwing","feidao");
		
		setup();
	        carry_object("/obj/armor/cloth")->wear();
		carry_object(__DIR__"obj/jinhua")->wield();

}

int accept_object(object who, object ob)
{	
	object jinlian;
	if (ob->query("name")==HIR "胭脂"NOR) {		//10s
	 	command("thank "+this_player()->query("id"));
	 	this_player()->set_temp("marks/redant",1);
	 	message_vision("红蚂蚁向$N抛了个媚眼，咯咯得笑个不停。\n", this_player());
    	return 1;
	}
	if (ob->query("name")=="烂瓦罐" 
			&& ob->query("liquid/name")=="极品女儿红" 
			&& ob->query("liquid/remaining")>10 ){			// 10g
		command("thank "+this_player()->query("id"));
	 	REWARD_D->riddle_set( this_player(),"巧过蚂蚁/红蚂蚁",1);
	 	message_vision("红蚂蚁高兴的忍不住重重亲了$N一下，咯咯得笑个不停。\n", this_player());
    	if (mapp (this_player()->query("riddle/巧过蚂蚁")))
		if (sizeof(this_player()->query("riddle/巧过蚂蚁"))==4)
			REWARD_D->riddle_done( this_player(),"巧过蚂蚁",50,1);	
    		
    	return 1;
    	}
	message_vision("红蚂蚁对着$N撇了撇小嘴道：“这东西能有什么用？”\n", this_player());
	return 0;
}
