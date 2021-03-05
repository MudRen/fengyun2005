#include <ansi.h>
inherit NPC;
void create()
{
        set_name("齐小燕", ({ "qi xiaoyan", "qi" }) );
        set("long",
                "一个穿的邋遢肮脏，鼻涕直流的“小男孩”。\n");
        set("gender", "女性" );
        set("age", 19);
        set("title", HIR"孩子王"NOR);
        set("chat_chance",1);
	set("chat_msg",	({
			"齐小燕焦急地道：我最心爱的小云雀飞跑了，你能帮我逮回来么？\n",
	})  );
        set("per", 30);
        
        set("combat_exp", 500000);
		
	set_skill("dodge",100);
	set_skill("parry",100);
	set_skill("sword",100);
	setup();
        carry_object("/obj/armor/cloth")->wear();
}

int accept_object(object who, object ob)
{	
	object sheepskin;
	
	if ( ob->query("name")=="精致鸟笼" && ob->query("skylark") )
	{ 
		write("齐小燕“啊”一声高兴地跳了起来，忙向你道谢：好心人，送你本我\n最近捡到的羊皮诗卷。”\n");
		sheepskin = new(__DIR__"obj/sheepskin");
            	sheepskin->move(who);
            	call_out("tell_secret", 3, who);
		return 1;
	}
	if ( ob->query("name")=="精致鸟笼" && !ob->query("skylark") )
	{
		write("齐小燕脸气得通红，使劲瞪了你一眼：找不到我的鸟就罢了，还用空\n笼子骗我，大坏蛋！\n");
		return 1;
       	}
	message_vision("$N看了看$n，懒懒的说，“除了我的小云雀，什么都不要。”\n",this_object(),who);
	return 0;
}

void tell_secret(object me)
{
	object obj;
	obj = this_object();
	me->set_temp("marks/guanwai_knowsecret",1);
	message_vision("$N又狡黠地眨了眨眼：“你对着墙上这个罗刹鬼女立个毒誓（swear），\n我就再告诉你一个秘密。”\n",obj);
	return ;
}
