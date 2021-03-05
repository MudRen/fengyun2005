#include <ansi.h>
inherit NPC;

void create()
{
        set_name("小伙计", ({ "huoji" }) );
        set("title", "临时帮忙的");
        set("gender", "男性" );
        set("age", 16);
        set("long","近来鹰记生意太好，卜鹰请来专门帮忙的。\n");

        set("combat_exp", 2000);
        set("attitude", "friendly");
        set("env/wimpy", 70);
        setup();
        carry_object("/obj/armor/cloth")->wear();
}
