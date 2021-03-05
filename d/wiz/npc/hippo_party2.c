#include <ansi.h>
inherit NPC;
inherit F_VENDOR;

void create()
{
        set_name("河马", ({ "he ma","hema" }) );
        set("gender", "男性" );
        set("title", CYN "零售商"NOR);
        set("age", 32);
        set("per", 30);
        set("price_modifier",1000000);
        set("long", "一副奸商的嘴脸，仿佛看透了一切。\n");
        set("combat_exp", 350000);
        set("chat_chance", 1);
        set("vendor_goods", ([
//"/obj/medicine/party/pill_chunjuan":300,
//"/obj/medicine/party/pill_shuijiao":300,
//"/obj/medicine/party/pill_niangao":300,
//"/obj/medicine/party/pill_tangyuan":300,
"/obj/medicine/party/pill_bai_zongzi":300,
"/obj/medicine/party/pill_rou_zongzi":300,
		]) );
        set("attitude", "friendly");
        set_skill("force", 60);
        set_skill("unarmed", 50);
        set_skill("dodge", 60);
        set_skill("zhaixin-claw",70);
        set_skill("cloud-dance",80);
        set_skill("parry",90);
        map_skill("unarmed","zhaixin-claw");
        map_skill("dodge","cloud-dance");
        setup();
        carry_object("/obj/armor/cloth")->wear();
}


void init()
{       
        object ob;

        ::init();
		add_action("do_vendor_list", "list");
}
