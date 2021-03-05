#include <ansi.h>
inherit NPC;

void create()
{
	set_name("嬉小玲", ({"xiaoling"}) );
        set("gender", "女性" );
        set("nickname", HIG "迷狼"NOR);
        set("long", "她穿得很随便，两边开叉的长裙，每走一步都会露出大腿来。\n");
 	set("attitude", "friendly");

	set("age", 15+random(5));

        set("combat_exp", random(100000)+100000);

        create_family("狼山", 1, "第四代弟子");
        set_skill("blade", 40+random(10));
        set_skill("parry", 40+random(10));
        set_skill("dodge", 40+random(10));
        set_skill("move", 40+random(10));
        set("chat_chance", 1);
        set("chat_msg", ({
		"嬉小玲看了下左右无人，偷偷对你说：“很奇怪呦！经常有野狼跑到\n望月岩跳崖自杀。”\n",
        }) );

        setup();
        carry_object(__DIR__"obj/skirt")->wear();
        if (!random(3))
        	carry_object(__DIR__"obj/conch");
}
