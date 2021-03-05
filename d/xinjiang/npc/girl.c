#include <ansi.h>
inherit NPC;
void create()
{
	set_name( "吐鲁番少女", ({ "pretty girl", "girl" }) );
	set("long", 
"这是一位妙龄少女，从小就生长在吐鲁番，长得唇红齿白，煞是好看！
\n");
	set("attitude", "friendly");
	set("age", 17);
        set("gender", "女性" );
	set("combat_exp", 50000);
        set("chat_chance", 15);
        set("chat_msg", ({
                "吐鲁番少女轻摆纤腰，跳着杜兰舞。\n",
                "吐鲁番少女轻启朱唇，唱着十二木卡姆。\n",
        }) );
	set_skill("unarmed", 1+random(100));
	setup();
        carry_object(__DIR__"obj/skirt")->wear();

}
