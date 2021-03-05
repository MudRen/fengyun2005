// butcher.c

inherit NPC;
inherit F_VENDOR;

void create()
{
        set_name("大胡子", ({ "beard butcher", "butcher" }) );
        set("title", "屠记肉铺");
        set("gender", "男性" );
        set("age", 35);
        set("long", "一个满脸大胡子和横肉的家伙。\n");
        set("str", 29);
        set("int", 14);
        set("combat_exp", 25000);
        set("attitude", "heroism");
        set_skill("unarmed", 200);
        set("vendor_goods", ([
                __DIR__"obj/yangtou": 120,
                __DIR__"obj/zhutou" : 120,
                __DIR__"obj/niutou" : 120,
        ]) );

        setup();
        carry_object("/obj/armor/cloth")->wear();

}

void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        add_action("do_vendor_list", "list");
	add_action("do_spare","spare");
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(4) ) {
                case 2:
                        say( "大胡子咧开大嘴, 笑着道：这位"  
                                + RANK_D->query_respect(ob)
                                + "，要买肉是吗? \n");
                        break;
        }
}

 
int do_spare(string arg)
{
	object me;
	object obj;
	string file;
	me = this_player();
	if(!arg) return notify_fail("指令：spare <name>\n");
	        if(!objectp(obj = present(arg, environment(me))))
                return notify_fail("这里没有"+arg+"。\n");
	if(base_name(obj) == "/obj/npc/pet" && obj->query("owner") == me->query("id")
	&& obj->query("possessed") == me)
	{
	message_vision("$N对大胡子说：＂帮我处理掉$n，我自己不忍动手！＂\n",me,obj);
	message_vision("$N伸手一抄，＂喀碴＂一声扭断了$n的脖子！\n",this_object(),obj);
	seteuid(ROOT_UID);
	file = obj->query_save_file()+".o";
	obj->die();	
	rm(file);
	seteuid(getuid());
	return 1;
	}	
	return notify_fail("你不可以这么做！\n");
}

void reset(){
    set("vendor_goods", ([
            __DIR__"obj/yangtou": 120,
            __DIR__"obj/zhutou" : 120,
            __DIR__"obj/niutou" : 120,
    ]) );	
}
