#include <ansi.h>
inherit NPC;

void create()
{
	object		biao, bag;

        set_name("粉燕子", ({ "fen yan zi", "fen" }) );
        set("nickname", "万里踏花");
        set("title", "大盗");
        set("gender", "男性");
        set("age", 27);
        set("per", 30);
        set("combat_exp", 50000);
        set("long",
		"一张少女般嫣红的脸，一身剪裁极和身的粉红色衣裳\n粉红色的腰带旁，斜挂着一支粉红色的腰囊。\n"
	);
        set("no_arrest",1);
        set_skill("move", 200);
        set_skill("dodge", 100);
        set_skill("notracesnow", 100);
        set_skill("throwing", 100);
        set_skill("feidao", 50);
	map_skill("throwing", "feidao");
	map_skill("dodge", "notracesnow");
	map_skill("move", "notracesnow");
        setup();
	biao = new(__DIR__"obj/biao");
	bag = new(__DIR__"obj/bag");
	biao->move(bag);
	bag->move(this_object());
	carry_object(__DIR__"obj/biao")->wield();
}

void init()
{
	object		me;

        ::init();
        if( interactive(me = this_player()) && !is_fighting() ) {
                call_out("greeting", 1, me);
        }
}

int greeting(object who)
{
	object		env;

	env = environment();
	if(present("ye gu hong", env)) {
		say( YEL "\n粉燕子上上下下打量着" + who->name() + "对叶孤鸿说道：这个人是我的，我不许你碰他。\n"NOR);
		say( YEL "\n叶孤鸿脸上露出种想呕吐的表情说道：男人女人你都要？\n"NOR);
		say( YEL "\n粉燕子笑了笑道：有时候我连你都想要。\n\n"NOR);
	}
	return 1;
}
