#include <ansi.h>
inherit NPC;
void create()
{
        set_name("柳夫人", ({ "mrs liu" }) );
        set("gender", "女性");
	set("age",35);
	set("env/wimpy",90);
        set("combat_exp", 10000);
        set("long",
		"柳夫人也是属狗的，比柳若松整整小十二岁，但是就算是最有眼力的
人都无法看出她的真实年纪。她的腰仍然纤细柔软，皮肤仍然柔滑光润，小腹
仍然光滑平坦，脸面绝没有一丝皱纹。\n"
	);
	set_skill("move",100);
        set_skill("dodge", 50);
	set_skill("unarmed",30);
        set("chat_chance", 1);
        set("chat_msg", ({
		name()+"媚笑道：听话的人，总是有好处的。\n",
		name()+"用一排雪白的牙齿轻轻的咬着樱桃般的红唇：你真的是个活人。\n",
        }) );
        setup();
	carry_object("/obj/armor/cloth")->wear();
}
