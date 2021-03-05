#include <ansi.h>

inherit NPC;

void create()
{
        set_name("岳洋", ({ "yue yang", "yue" }) );
        set("long","他年纪还很轻，黝黑英俊的脸上，带着几分傲气，又带着几分野气，\n眼睛黑得发蓝，薄薄的嘴唇显得很坚强而残忍。\n");
        set("attitude", "heroism");
        set("title", "初入江湖");
        set("per", 25);

        set("combat_exp", 80000);

        set_skill("unarmed", 100);
        set_skill("spear", 70);
        set_skill("yue-spear", 50);
        set_skill("parry", 70);
        set_skill("dodge",50);
        set_skill("move", 100);
		set_skill("force",100);
		set_skill("puti-steps",40);
		set_skill("manjianghong",80);
		
		map_skill("force","manjianghong");
		map_skill("dodge","puti-steps");
        map_skill("spear", "yue-spear");
        
        set("chat_chance", 1);
        set("chat_msg", ({
        "岳洋眺望着一望无际的大海，握紧了拳头，默默道：一定要闯出个名堂！\n",
	}) );
    	set("chat_chance_combat", 10);
    	set("chat_msg_combat", ({
        (: perform_action, "spear.zonghengtianxia" :),
	}) );

        setup();
        carry_object("/obj/armor/cloth")->wear();
        carry_object(__DIR__"obj/egg");
        carry_object(__DIR__"obj/by_spear")->wield();
}
