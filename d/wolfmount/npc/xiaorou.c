#include <ansi.h>
inherit NPC;

void create()
{
	set_name("嬉小柔", ({"xiaorou"}) );
        set("gender", "女性" );
        set("nickname", HIG "迷狼"NOR);
        set("long", "她穿得很随便，两边开叉的长裙，每走一步都会露出大腿来。\n");
 	set("attitude", "friendly");
/*	set("max_gin", 300);
	set("max_kee", 300);
	set("max_sen", 300);  */
	set("age", 15+random(5));

        set("combat_exp", random(100000)+100000);
        create_family("狼山", 1, "第四代弟子");
        set_skill("blade", 40+random(10));
        set_skill("parry", 40+random(10));
        set_skill("dodge", 40+random(10));
        set_skill("move", 40+random(10));
        set("chat_chance", 1);
        set("chat_msg", ({
		"嬉小柔眼睛里带着种梦幻般的憧憬，痴痴道：“每天吹起七彩海螺时，\n就是黎明到来的时刻。”\n",
        }) );

        setup();
        carry_object(__DIR__"obj/skirt")->wear();
        if (!random(3))
        	carry_object(__DIR__"obj/conch");
}
