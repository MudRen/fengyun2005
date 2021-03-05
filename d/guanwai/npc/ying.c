#include <ansi.h>

inherit NPC;

void create()
{
        set_name("卜鹰", ({ "ying" }) );
        set("gender", "男性" );
        set("long",
                "兀鹰般的锐眼，幽灵般的白衣，刀锋般的冷酷，山岳般的镇定。\n" );
        set("title", GRN"草原之鹰"NOR);
        set("attitude", "peaceful");
	set("age", 44);
        set("per", 20);
        set("combat_exp", 10000000);
        set_temp("apply/damage",50);
        set("chat_chance", 1);
        set("chat_msg", ({
                "卜鹰用一种讥诮的目光冷冷地盯着你。\n",
                }) );
        set_skill("unarmed", 200);
        set_skill("parry", 200);
        set_skill("dodge", 300);
        set_skill("blade", 200);
        set_skill("shortsong-blade", 100);
        set_skill("fall-steps", 100);
        set_skill("bolomiduo", 100);
	set_skill("blade", 200);
        map_skill("force", "bolomiduo");
        map_skill("dodge", "fall-steps");
	map_skill("parry", "shortsong-blade");
        map_skill("blade", "shortsong-blade");

	setup();
        carry_object("/obj/armor/cloth")->wear();
        carry_object(__DIR__"obj/guskin");
	carry_object(__DIR__"obj/roundblade1")->wield();
}

void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() )
        {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        add_action("do_continue","continue");
}

void greeting(object ob)
{
        object npc;
        npc = this_object();
        if( !ob || environment(ob) != environment() ) return;
        if( ob->query("score") > 1500 && ob->query_temp("marks/guanwai_knowsecret") )
        {
        	message_vision("$N喝了口古城烧，锐眼中现出一丝笑意，漫声而歌：\n　　　儿须成名～～酒须醉～～～。\n",npc);
        	message_vision("$N转过头来看了看$n笑道：唱下去！（continue .....） \n",npc,ob);
        	set("enable_continue",1);
        }
        else
        {
        	message_vision("$N喝了口古城烧，用一种讥诮的目光冷冷地盯着$n。\n",npc,ob);
        }
}

int do_continue(string arg)
{
	object npc,player;
	npc = this_object();
	player = this_player();

	if(!query("enable_continue")) return 0;
	if ( !arg )
		return notify_fail("你要继续唱什么？\n");
	if (arg == "醉后畅谈～～见心言～～～" || arg == "醉后畅谈见心言" || arg == "醉后畅谈见心言。" )
        {
        	delete("enable_continue");
        	message_vision("$N击掌应声和唱：醉后畅谈～～见心言～～～。\n",player);
        	call_out("ask_help",3,npc,player);
	}
	else
		message_vision("$N扯着嗓子胡乱唱到："+arg+"。\n",player);
	return 1;
}

void ask_help(object npc,object player)
{
	object sword;
	message_vision("$N哈哈大笑道：好好，好一个见心言！来来，帮我个忙，找到小方，\n把这把魔眼剑给他。叫他不用再瞎担心了。\n",npc);
	sword = new(__DIR__"obj/magicsword");
	sword->set("owner_id",player->query("id"));
	sword->move(player);
	message_vision("$N拿出一把魔眼剑交给$n。\n",npc,player);
	player->delete_temp("marks/guanwai_knowsecret");
	player->set_temp("marks/guanwai_help_ying",1);
	return;
}
