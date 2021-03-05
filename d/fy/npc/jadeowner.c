#include <ansi.h>
inherit NPC;
inherit F_VENDOR;

void create()
{
        set_name("商玉龙", ({ "jade seller", "seller" }) );
        set("gender", "男性" );
        set("age", 49);
		set("title", "玉龙珠宝");
        set("long", "这是一位肥肥胖胖的店掌柜，可别小看了他，玉龙珠宝店是风云城里的老字号了，
商玉龙的眼光也是出奇的准，真玉假玉，一看便知。\n");
        set("combat_exp", 1200000);
        set("reward_npc", 1);
        set("difficulty", 2);
		set("str", 60);
		
		set("inquiry", ([
        	"古董三":	"古董三，古董三，原名叫英穷死，就是那个有名的探宝大王了。\n",
    	]) );
		
		set("force_factor",60);
        set("attitude", "friendly");
        set_skill("dodge", 100);
        set_skill("parry", 120);
        set("vendor_goods", ([
                __DIR__"obj/jade1":7,
                __DIR__"obj/jade2":7,
                __DIR__"obj/jade3":7,
                __DIR__"obj/jade4":7,
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
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(10) ) {
                case 0:
                        say( " 店掌柜笑着道：这位"
                                + RANK_D->query_respect(ob)
                                + "，买玉吗？ \n");
                        break;
                case 1:
                        say( " 店掌柜笑着道：这位"
                                + RANK_D->query_respect(ob)
                                + "，玉是吉祥之物，买一块吧。 \n");
                        break;
		}
}

int accept_object( object who, object item){
		
		if (item->query("name") == HIM"紫晶宝石"NOR && item->query("jile")==1){
			if (REWARD_D->riddle_check(who,"紫晶之谜")==2 
				|| REWARD_D->riddle_check(who,"紫晶之谜/商玉龙")) {
				command("shake");
				command("say 你还是另找高人吧。");
				return 0;
			}
			
			message_vision(CYN"$N拿起"+item->query("name")+NOR+CYN"掂了几下，又拿出个镜片端详片刻，眉头紧锁。\n"NOR, this_object());
			ccommand("say 此物甚是蹊跷，其质也温，其声也脆，不似是寻常紫玉。");
			ccommand("shake");
			REWARD_D->riddle_set(who,"紫晶之谜/商玉龙",1);
			
			if (sizeof(who->query("riddle/紫晶之谜"))==4) {
				tell_object(who, CYN"\n"+name()+CYN"说：只有一个人会知道这块宝石的来历，他的名字叫古董三。
据说此人自三岁起就跟着他老爹在古墓里打转，这黑道白道上流转的宝物，
没有他不知道来历的，他一定知道这宝石的底细。\n");
				REWARD_D->riddle_set(who,"紫晶之谜",2);
			}
			
			return 0;
		}
			
		if (item->query("thief_obj")){
			command("say 小店不收来历不明之物。");
			return 0;
		}
				
}

int do_sell(string arg)
{
	object ob;
	int value;
	if( !arg || !(ob = present(arg, this_player())) )
		return notify_fail("你要卖断什麽物品？\n");
        if( this_player()->is_busy() )
                return notify_fail("你上一个动作还没有完成，不能卖物品。\n");
	if( ob->query("money_id") )	return notify_fail("你要卖「钱」？\n");
	value = ob->query("value");
        if( !(value/10) ) return notify_fail("这样东西并不值很多钱。\n");
	if (!ob->query("thief_obj"))
	{
		return notify_fail("店掌柜摇头道：本店不收这类物品。\n");
	}
	message_vision("$N把身上的" + ob->query("name") + "偷偷塞给店掌柜....\n",this_player());
	command("whisper "+this_player()->query("id")+" 现金交易太扎眼，钱会转到你南宫银行的帐上。\n");
	command("snicker");
	this_player()->add("deposit",value/10);
	destruct(ob);
	this_player()->start_busy(1);
	return 1;
}