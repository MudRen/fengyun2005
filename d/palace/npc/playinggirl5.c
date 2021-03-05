#include <ansi.h>
inherit NPC;
void create()
{
//	int i,amun;
	set_name("红中" , ({ "playing girl", "girl" }) );
	set("long", "这是一位帝王谷的小丫头，专陪客人下棋．\n");
	set("attitude", "friendly");
	set("age", 13);
        set("gender", "女性" );
        set("chat_chance", 1);
        set("chat_msg", ({
                "小丫头窃窃道：听说要静侯三个时辰．．．．才肯．\n",
        }) );

	set("combat_exp", 250000);

	set_skill("throwing",250+random(100));
	set_skill("dodge", 50+random(50));

	setup();
	carry_object("/obj/armor/cloth")->wear();
	
	if (random(3)>1) {carry_object(__DIR__"obj/pai1");
				carry_object(__DIR__"obj/pai2");
				}
		else if (random(3)>0) {
			carry_object(__DIR__"obj/pai2");
			carry_object(__DIR__"obj/pai3");
			}
		else {
			carry_object(__DIR__"obj/pai3");
			carry_object(__DIR__"obj/pai1");
			}
}