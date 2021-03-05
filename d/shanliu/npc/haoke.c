
inherit NPC;

void create()
{
        set_name("大胡子豪客", ({ "dahuzi haoke", "haoke"}) );
        set("gender", "男性" );
        set("age", 32);
        set("long", "这是一位满脸大胡子的江湖大豪客，一看就是有钱的主。\n");
        set("combat_exp", 300000);
		set("str",40);
        set("fle",30);
        set_skill("dodge", 100);
        set_skill("iron-cloth",150);
   		set_skill("unarmed", 220);
        set("chat_chance", 1);
        set("chat_msg", ({
"大胡子豪客红着眼嚷道：这把赌的，过瘾！真他姥姥的够劲儿！\n",
        }) );
	
		setup();
        carry_object("/obj/armor/cloth")->wear();
}

