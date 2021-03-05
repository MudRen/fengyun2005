#include <ansi.h>
inherit NPC;
void create()
{
        set_name("柳若松", ({ "mr liu" }) );
        set("gender", "男性");
        set("combat_exp", 10000);
	set("age",47);
	set("env/wimpy",90);
        set("long","
柳若松从几个月前就开始进补，一连吃了两条虎鞭，好几副
黄教大喇嘛秘方配制的神丹。\n"
	);
	set_skill("move",100);
        set_skill("dodge", 50);
	set_skill("unarmed",50);

        set("chat_chance", 1);
        set("chat_msg", ({
		name()+"苦笑道：现在你总该知道我是不是真的听话了！\n",
		name()+"道：我虽然是个活人，可是我心里会打什么主意，用不着等我说出来，你也能猜得到的。\n"
        }) );
        setup();
	carry_object("/obj/armor/cloth")->wear();
}
