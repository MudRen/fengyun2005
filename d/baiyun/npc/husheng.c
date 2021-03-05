#include <ansi.h>

inherit NPC;

void create()
{
        set_name("胡生", ({ "husheng" }) );
        set("long","一张又长又狭的马脸，不停露出残酷的笑容。\n");
        set("attitude", "heroism");
        set("per", 10);

        set("combat_exp", 20000);

        set_skill("parry", 100);
        set_skill("dodge", 100);
        set_skill("move", 100);

        set("chat_chance", 1);
        set("chat_msg", ({
        	"胡生突然诡异地一笑。\n",
        }) );
        setup();
        carry_object("/obj/armor/cloth")->wear();
}
