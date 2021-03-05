// serpent.c

inherit NPC;

void create()
{
        set_name("黑冠巨蟒", ({ "serpent" }) );
        set("long", "一只乌黑油亮的巨蟒，头上生著一个大肉瘤。\n");

        set("race", "蛇类");
        set("age", 400);
        set("attitude", "aggressive");

        set("combat_exp", 150000);
        
        setup();
}
