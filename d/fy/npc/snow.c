inherit NPC;
inherit F_VENDOR;
#include <ansi.h>

int do_qrestore();
int insurance();

void create()
{
    set_name("上官雪儿", ({ "shangguan xuer", "snow","xuer" }) );
	set("gender", "女性" );
	set("age", 12);
	set("title", CYN "漂泊四海"NOR);
	set("long","一个梳着两条辫子的小女孩，正掩着嘴偷偷的乐。\n");
	set("combat_exp", 150000);
	set("attitude", "friendly");
	set("NO_KILL","这么可爱的小女孩儿，你怎么忍心下手？\n");
	set("per",30);
	set("vendor_goods", ([
		"obj/item/player_bag1": 100,
		"obj/item/player_bag2": 100,
		"obj/item/player_bag3": 100,	
		"obj/item/ccard":		100,
		"obj/item/keychain":	100,
		"obj/item/gold_pawncard": 100,
		"obj/item/silver_pawncard": 100,
			
	]) );
	
	set("inquiry", ([
	       	"insurance": 	(: insurance :),
	       	"财产保险": 		(: insurance :),
	       	"玄灵玉盒":		(: do_qrestore :),
			"treasurebox":		(: do_qrestore :),
			"treasure box":		(: do_qrestore :),
         ]) );
		
	set_skill("unarmed",150);
	set_skill("dodge",150);
	set_skill("parry",150);
	setup();
	carry_object("/obj/armor/cloth")->wear();
}

void init(){
	add_action("do_vendor_list","list");
	::init();
}

int do_qrestore(){
	
	object me, ob/*, newob*/;
	string id,file;
	int num;
	mapping t_items = ([]);
		
	me = this_player();
	
	if (present("treasure box", me)) {
		command("giggle");
		command("say 玄灵玉盒不是已经在你的身上了么？");
		return 1;
	}
	
	seteuid(ROOT_UID);
	
	if (!me->query("update/12_treasurebox")) {
		id = me->query("id"); 
		file = sprintf(DATA_DIR "user/%c/%s/treasurebox", id[0],id);
		ob = new("/obj/item/questbox");
		if (!ob) {
			write("文件读写错误，请立即通知在线巫师。\n");
			return 1;
		}
		
		ob->set("owner_id", id);
		if( file_size(file + __SAVE_EXTENSION__) >= 0 ) {
			ob->restore();
			if (mapp(t_items = ob->item_list()))
				num = sizeof(ob->item_list());
			else
				num = 0;
			
			if (num >0)  
				me->set_items(t_items);
			
			if (rm(file+ __SAVE_EXTENSION__))
				log_file( "QBOX_LOG", sprintf("(%s) %s 的玄灵玉盒转换成功（%d）。\n", 
				ctime(time()),
				me->query("id"),
				num)
				); 
			else {
				log_file( "QBOX_LOG", sprintf("(%s) %s 删除原文件失败。\n", 
				ctime(time()),
				me->query("id")));
				write("文件读写错误，请立即通知在线巫师。\n");
			}
		} 
		destruct(ob);
		me->set("update/12_treasurebox",1);		
	}
		
	ob = new("/obj/item/newquestbox");			
	if (ob->move(me)) {
		message_vision("上官雪儿笑嘻嘻地从后房里捧出一个小盒子递给$N。\n", me);
		return 1;
	}
	tell_object(me,"上官雪儿说：啊呀，您身上东西太多（重）了，没法给你呀！\n");
	destruct(ob);
	return 1;		
}


int insurance(){
	object me = this_player();
	int duration;
	
	duration = me->query("timer/insurance")+ 259200 - time();
	if (duration >0) {
		tell_object(me, CYN"上官雪儿说：客官您的保险还有"+ (duration/3600)+"小时"
		 + (duration%3600)/60 + "分钟左右才过期呢。\n"NOR); 
		return 1;
	}
			
	message_vision(YEL"$N点了点头，从柜台上拿出个奇形怪状的比牌九要大上两号的东西飞快地按
了几下，那东西上面亮闪闪的闪烁了几下，最后嘟嘟地叫了几声。\n\n"NOR, this_object());

	if (me->query("deposit")< 50000) {
		tell_object(me,name()+"摇了摇头说，客官您钱庄的存款不够啊（需足金五两）。\n");
		return 1;
	}
	me->add("deposit",-50000);
	command("ya");
	tell_object(me,CYN"上官雪儿说：好了，客官您就安心出门吧，保险三天有效。\n"NOR);
	me->set("timer/insurance",time());
	return 1;		
}


void reset()
{
	set("vendor_goods", ([
		"obj/item/player_bag1": 100,
		"obj/item/player_bag2": 100,
		"obj/item/player_bag3": 100,	
		"obj/item/ccard":		100,	
		"obj/item/keychain":	100,
		"obj/item/gold_pawncard": 100,
		"obj/item/silver_pawncard": 100,
	]) );
}
		