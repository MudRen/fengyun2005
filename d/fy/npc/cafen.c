// waiter.c

inherit NPC;
inherit F_VENDOR;
int tell_him();
void create()
{
	set_name("胡英", ({ "hu ying","hu" }) );
	set("gender", "男性" );
	set("title", "棺材店老板");
	set("age", 55);
	set("long","这位老人的脸上布满绉纹．．．\n");
	set("combat_exp", 5000);
	set("attitude", "friendly");
	set("per",30);
	set("vendor_goods", ([
        	__DIR__"obj/zhiqian":100,
        	__DIR__"obj/zhihua":100,
        	"/obj/item/paper_seal":300,
	]) );
    	set("inquiry", ([
        	"coffin" : (: tell_him :),
        	"棺材" : (: tell_him:),
        ]));
	set_skill("unarmed",5);
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
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(10) ) {
                case 0:
message_vision("$N看了$n一眼道：木棺没货，都订了，太多人死了。\n",this_object(),ob);
                        break;
                case 1:
message_vision("$N向$n问道：谁死了？\n",this_object(),ob);
                        break;
        }
}

int tell_him()
{
    object me;
    me =this_player();
	if (REWARD_D->riddle_check( me, "勇探地牢")==1
		|| REWARD_D->riddle_check( me, "勇探地牢")==2) {    
      	tell_object(me,"胡英道：乙成仙说你死，你一定会死的了，可是我这儿没有木材了！\n");
    	tell_object(me,"胡英道:你去砍些木材来我也许会给你做一个.\n");
        REWARD_D->riddle_set( me,"勇探地牢", 2);
        return 1;
    } 
    return 0;
}

int accept_object(object who, object ob)
{
    if( (string) ob->query("name") == "梅树幼苗" 
    	&& REWARD_D->riddle_check( who,"勇探地牢")==2) {
		if(ob->query_amount()<20) {
			tell_object(who,"胡英道：这不够给你做个好棺材的！\n");
			return 0;
		} else {
			tell_object(who, "胡英指着墙角的红木棺材道：你认为那棺材的式样如何？\n");
			tell_object(who, "你发现红木棺材的盖没有盖好，似乎可以推开（ｐｕｓｈ）。\n");
			REWARD_D->riddle_set( who,"勇探地牢", 3);        			}
        	return 1;
	}	
    return 0;
}

void reset()
{
	set("vendor_goods", ([
        __DIR__"obj/zhiqian":100,
        __DIR__"obj/zhihua":100,
        "/obj/item/paper_seal":300,
	]) );
}
