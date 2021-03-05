inherit NPC;
#include <ansi.h>

void create()
{
        set_name("卫天鹰", ({ "wei tianying", "wei"}) );
        set("gender", "男性" );
        set("age", 34);
	set("per", 35);

	set("class","legend");
	set("attitude","friendly");
        
        set("nickname", HIR"魔刀"NOR);
        set("title", "青龙会 十二煞");
        set("long","一身黑衣，鹰爪般干枯的手紧紧握着把刀，嘴角不时露出嘲弄的笑容。\n");
        
        set("combat_exp", 2900000);
        
        set_skill("move", 150);
        set_skill("dodge", 150);
        set_skill("force", 150);
        set_skill("blade",150);
	set_skill("puti-steps",180);
	set_skill("shortsong-blade", 150);
	set_skill("lingxi-zhi",150);
	set_skill("unarmed",150);
	set_skill("move",150);
	set_skill("parry",120);
	set_skill("qidaoforce",120);
	
	map_skill("force","qidaoforce");
	map_skill("parry","shortsong-blade");
	map_skill("unarmed","lingxi-zhi");
	map_skill("dodge", "puti-steps");
	map_skill("blade", "shortsong-blade");
	
	set("chat_chance_combat", 40);
        set("chat_msg_combat", ({
                (: perform_action, "blade.duangechangmeng" :),
        }) );
	
	set("chat_chance", 1);
        set("chat_msg", ({
                "卫天鹰嘴角露出残酷的冷笑，嘿嘿道：一块破布，就叫这帮蠢猪连钱\n带命送上门来，真是有趣。\n",
                "卫天鹰嘿嘿冷笑道：天上白玉京，现在趴在地上跟烂泥一样，幺妹，\n还不进去宰了他。\n",
        }) );
        set("inquiry",([
	        "孔雀图"  :"嘿嘿。。这个么不能说，不能说。。\n",
	        "design"  :"嘿嘿。。这个么不能说，不能说。。\n",
	        "白玉京"  :"什么天上白玉京，碰到我卫天鹰不还是地上一堆烂泥。。哈哈。。\n",
	        "bai"  :"什么天上白玉京，碰到我卫天鹰不还是地上一堆烂泥。。哈哈。。\n",
	        "袁紫霞"  :"幺妹最近好象有点怪。。。莫非。。。\n",
	        "yuan"  :"幺妹最近好象有点怪。。。莫非。。。\n",
                ]) );

        setup();
        carry_object(__DIR__"obj/black_cloth")->wear();
	carry_object(__DIR__"obj/long_blade")->wield();
}

void init()
{
        object ob;
        ::init();
        ob = this_player();
        call_out("greeting", 1, ob);
}

int greeting(object ob)
{	
	object room;
	object hotel;
	
	if (!ob || environment(ob)!=environment())	return 1;
		
	room = find_object("/d/chenxiang/fyyard");
	if(!objectp(room)) room = load_object("/d/chenxiang/fyyard");
	hotel = find_object("/d/chenxiang/tingfengge");
	if(!objectp(hotel)) hotel = load_object("/d/chenxiang/tingfengge");
	
	if (room == environment(this_object()) && ob->query_temp("marks/longlife_getmap"))  
	{
		message_vision("$N阴阴的笑着：杀了我的手下，偷了我的珠宝。胆子不小啊！\n",this_object());
		this_object()->kill_ob(ob);
		ob->kill_ob(this_object());
		ob->delete_temp("marks/longlife_getmap");
		return 1; 
	}
	if( hotel == environment(this_object()) && ob->query_temp("marks/longlife_getmap") ) {
		this_object()->remove_all_killer();
		ob->remove_all_killer();
	}
	return 0;
}
