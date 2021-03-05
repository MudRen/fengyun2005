#include <ansi.h>;
inherit NPC;

void create()
{
	set_name("小鹿", ({ "little deer", "deer", "xiao lu"}) );
    set("race", "野兽");
    set("age", 5);
    set("long", "一头浅浅茸毛身上带着白色斑点的小鹿。\n");
    set("max_kee", 120);
    set("limbs", ({ "头部", "身体", "前脚", "後脚", "尾巴" }) );
    set("verbs", ({ "bite" }) );
	set("chat_chance", 5);
	set("chat_msg", ({
		"小鹿低头嗅嗅还带有露水的青草。\n",
		"小鹿靠近你，毛茸茸的头轻轻的拱了拱你，似乎在向你要吃的样子。\n",
		"小鹿悠闲的在树下徘徊。\n",
		}) );
    set_skill("dodge", 100);
	set("combat_exp", 100);

    setup();
}


int accept_object(object who, object ob)
{
	object deer, me, obj;
	
	me = this_player();
	deer = this_object();
	
    if(ob->query("marks/deerfood"))
    {
		message("vision", deer->name() + "低头闻闻你手中的" + ob->name() + "舌头一卷就把"
				+ ob->name() + "卷进了嘴里。\n", me);
		message("vision", deer->name() + "走过去低头闻闻" + me-> name() + 
				"手中的" + ob->name() + "舌头一卷就把\n"
				+ ob->name() + "卷进了嘴里。\n", environment(), me);
		if(random(10)<3) {
			message_vision(YEL"$N低头在$n的身上蹭了蹭，一团绒毛掉了下来。\n"NOR, 
					this_object(), me);
		    obj = new(__DIR__"obj/hair");
		    obj->move(environment());
		}
        return 1;
    }
    message("vision", deer->name() + "走了过去，低头嗅了嗅" + me->name() + "手中的" 
    		+ ob->name() + "，转身走了开去。\n", environment(), me);
    return notify_fail(deer->name() + "走了过来，低头嗅了嗅你手中的" 
    		+ ob->name() + "，转身走了开去。\n");
}