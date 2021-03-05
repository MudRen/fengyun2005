// xiaojuan.c

inherit NPC;

void create()
{
	set_name("小娟", ({ "xiao juan","juan" }) );
	set("title", "民女");
	set("gender", "女性" );
	set("age", 16);
	set("str", 1);
	set("per", 30);
	set("long", @LONG
小娟姓刘，是这里刘老农的独生女。今年十六岁，人长的漂亮又大方。
正在这里洗衣裳。你也许想和她谈谈(talk)。
LONG
);
	set("combat_exp", 1);
	set("attitude", "friendly");
/*        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
		"唉！ 没料道你和那些坏人是一伙的！\n",
	}) );*/

	setup();
	carry_object(__DIR__"obj/pink_cloth")->wear();
}


int accept_fight(object me)
{
	command("say 小女子哪里是您的对手？");
	return 0;
}


void init()
{
        add_action("do_contact", "talk");
}

int do_contact(string arg)
{
        write(" 小娟也扭过头来，对你愉快地微笑著。露出两个浅浅的酒窝儿。\n");
	command( "say  您从哪里来的呀？");
        call_out("kidnaping", 10);
        return 1;
}

void kidnaping()
{
        object room;
        if( room = find_object(AREA_CHUENYU"sunnyroad"))
        	room->set("exits/north",AREA_CHUENYU"base_b_mtn");
        else 
        	return;
        message("vision", " 突然间！ 从北面窜出三个青衣蒙面人扑向小娟…… \n", room );
        message("vision", " 蒙面人狰狞的笑道：“堡主今晚又有的享用了¨¨ \n", room );
        message("vision", " 小娟无力的挣扎着，向你高叫着：“救命啊，救命啊！\n ", room);
        message("vision", " 蒙面人将小娟装入大布袋，向黑松山遁去。\n", room );
	destruct( this_object());
}

