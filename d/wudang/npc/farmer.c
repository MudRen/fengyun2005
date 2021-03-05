#include <ansi.h>
inherit NPC;

void create()
{
        set_name("放牛娃", ({ "little farmer", "farmer" }) );
        set("gender", "男性");
        set("age", 12);
        set("combat_exp",2000);
        set("long", "一个十来岁的放牛娃，正在田里赶牛。\n");
	
	set("inquiry", ([
        	"bull": "好好的一头牛，在地里跑了一圈突然就不行了，这可怎么办？\n",
        	"大水牛": "好好的一头牛，在地里跑了一圈突然就不行了，这可怎么办？\n",
        	"生病":	"好好的一头牛，在地里跑了一圈突然就不行了，这可怎么办？\n",
         ]) );
	
	set_skill("blade", 10+random(50));
        setup();
	carry_object(__DIR__"obj/liandao")->wield();
	carry_object("/obj/armor/cloth")->wear();
}


int accept_object(object who, object item){
	
	if (item->query("name") == "七彩蝎子的尸体") {
		ccommand("ack");
		message_vision(CYN"放牛娃说：原来是这个家伙在捣鬼呀，太感谢你了！\n"NOR, who);
		message_vision(CYN"放牛娃凑在你耳边悄悄地说：“告诉你个秘密，这儿麦田里常有些奇怪的人来。”\n"NOR,who);
		
		if (QUESTS_D->verify_quest(who, "武当大水牛"))
			QUESTS_D->special_reward(who, "武当大水牛");
		return 1;
	}
	return 0;
}
			