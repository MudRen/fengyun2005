inherit NPC;

void create()
{
        set_name("五彩神仙鱼", ({ "fish","colorful fish" }) );
        set("race", "游鱼");
        set("age", 3);
        set("long", "一条鱼头鱼脑的野鱼，在日光辉映下，身上变换出五彩的颜色，美丽异常。\n");
	set_skill("dodge", 80);
	set("combat_exp",10000);
        setup();
}