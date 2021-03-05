// thousand_hand.c

#include <ansi.h>

inherit NPC;
void create()
{
//	int i,amun;
	string *name= ({"小兰", "牡丹", "冬青", "玫瑰", "杜鹃"});
	set_name( name[random(5)] , ({ "pretty girl", "girl" }) );
	set("long", "这是一位帝王谷的小丫头\n");
	set("attitude", "friendly");

	set("age", 13);
        set("gender", "女性" );
        set("chat_chance", 1);
        set("chat_msg", ({
                "小丫头窃窃道：听说要静侯三个时辰．．．．才肯．\n",
        }) );


	set("str", 35);
	set("cor", 30);
	set("cps", 25);

	set("combat_exp",50000);
	set_skill("throwing",300);
	set_skill("dodge", 50+random(50));

	setup();
	carry_object("/obj/armor/cloth")->wear();
        carry_object(__DIR__"obj/anqi")->wield();
}