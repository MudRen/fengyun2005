#include <ansi.h>
inherit NPC;
void create()
{
        set_name("大老板", ({ "big boss" }) );
        set("gender", "男性");
        set("combat_exp", 10000);
	set("age",47);
	set("env/wimpy",90);
        set("long",
		"大老板身上穿着一件普通的布衣，怎么看也不像个老板。\n"
	);
	set_skill("move",100);
        set_skill("dodge", 50);
	set_skill("unarmed",50);
        set("chat_chance", 1);
        set("chat_msg", ({
	name()+"弓下腰，仿佛要嗅嗅花香，却突然出手，用两个手指捏住只飞虫，
然后才慢慢的问道：“你们说那个人叫什么名字？”\n",
	name()+"道：“阿吉？没有用的阿吉？”\n",
	name()+"微笑点头，觉得很满意，他喜欢别人记住他说的话，最好是每一句话。\n"
        }) );
        setup();
	carry_object("/obj/armor/cloth")->wear();
}
