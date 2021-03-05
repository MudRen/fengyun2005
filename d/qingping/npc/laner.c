// XXDER
inherit NPC;
void create()
{
	set_name("兰儿" , ({ "laner" }) );
	set("long", "这是一位眉目清秀的小丫头，她正在清扫房间。\n");
	set("attitude", "friendly");

	set("age", 13);
        set("gender", "女性" );
        set("chat_chance", 5);
        set("chat_msg", ({
           "兰儿低声道：讨厌的鸟儿，害的我天天要清扫院子．． \n",
        }) );
        set("inquiry", ([
          "鸟儿": "大槐树上那窝鸟儿真讨厌，害的我天天要清扫院子．．\n",
          "bird": "大槐树上那窝鸟儿真讨厌，害的我天天要清扫院子．．\n",
        ]) );
	set("combat_exp", 5000);
	set_skill("dodge", 50+random(50));
	setup();
	carry_object("/obj/armor/cloth")->wear();
}
