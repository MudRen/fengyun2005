#include <ansi.h>
inherit NPC;
void create()
{
        set_name("李大嘴", ({ "dazui" }) );
        set("gender", "男性");
        set("combat_exp", 500000);
        set("title", HIW "恶人"NOR);
        set("long",	"恶人谷中的一员，好吃人肉，邪功盖世\n");
        
        
        set("inquiry", ([
        	"铁萍姑":	"铁萍姑是我的乖闺女啊。\n",
        	"回家":		"不成，老子过不惯那儿的日子。\n",
        ]));
        
        set_skill("move", 50);
        set_skill("dodge", 200);
		set_skill("unarmed",250);
		set("str",55);
        set("chat_chance", 1);
        set("chat_msg", ({
                (: random_move :)
        }) );
        setup();
	carry_object("/obj/armor/cloth")->wear();
}

void init()
{
	object		me;

        ::init();
        if( interactive(me = this_player()) && !is_fighting() && !random(5)) {
		add_action("do_accept", "accept");
                call_out("greeting", 1, me);
        }
}

int greeting(object me)
{
		if (!me || environment(me)!= environment()) return 1;
			
		message_vision(HIY "\n$N对$n说道：我可以将你师傅的内力全部
吸出来给你，怎么样？（accept yes/no）\n"NOR, this_object(), me);
	return 1;
}

int do_accept(string arg)
{
	if( arg != "yes" &&  arg != "no") 
                return notify_fail("你要接受什么？\n");
	if( arg == "yes") {
		message_vision( HIY "$N说道：好！今夜午时见！\n"NOR, this_object());
	}
	else {
        message_vision( HIY "$N说道：真是不识抬举！拿命来！\n"NOR, this_object());
		kill_ob(this_player());
        }
	return 1;
}

