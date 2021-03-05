#include <ansi.h>
inherit NPC;

void create()
{
	set_name("嬉小卜", ({"xiaobu"}) );
        set("gender", "男性" );
        set("nickname", HIG "迷狼"NOR);
        set("long", "一个赤足穿着双草鞋，头发乱得象鸡窝的少年。\n");
 	set("attitude", "friendly");
/*	set("max_gin", 300);
	set("max_kee", 300);
	set("max_sen", 300); */
	set("age", 15+random(5));

        set("combat_exp", random(100000)+100000);
        create_family("狼山", 1, "第四代弟子");
        set_skill("blade", 40+random(10));
        set_skill("parry", 40+random(10));
        set_skill("dodge", 40+random(10));
        set_skill("move", 40+random(10));
        set("chat_chance", 1);
        set("chat_msg", ({
        "嬉小卜吃吃地笑着：我喜欢看好看的女人，更喜欢和好看的女人。。。\n",
        }) );

        setup();
        carry_object(__DIR__"obj/shorts")->wear();
        carry_object(__DIR__"obj/shoes")->wear();
        if (!random(3))
        	carry_object(__DIR__"obj/conch");
}
