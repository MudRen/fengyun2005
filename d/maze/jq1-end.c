// Sinny-silencer@fy4 workgroup 

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "宣武堂内室");
	set("long", @LONG
一张舒适柔软的大床放在正中，轻柔洁白的挂纱如同凝脂一样从上而下，洒在
周地上，朦胧轻纱之间，似乎有一对纠缠的人影在白纱中来回翻滚，春色无边，浓
腻无方，勾人心魄的女子的嘤咛娇喘不时入耳。。。。 
LONG
	);
	set("no_clean_up", 0);
	set("no_fly",1);
	set("exits",([
		"west" : __DIR__"jq1-exit",

	]));
        set("objects", ([
                __DIR__"npc/jq1-lufengxian": 1,
                __DIR__"npc/jq1-meihuadao": 1,
        ]) );

        set("item_desc", ([
	]) );
	setup();
	
}


string *event1_msg=	({
	
	WHT"\n流苏影动之间，那对紧紧纠缠在一起的人影乍地分了开来。\n"NOR,
	
	WHT"“嘿，何人如此猖狂？到武堂中搅我吕凤先的好事？” \n"NOR,
	
	WHT"梅花盗懒散地斜靠轻纱中，扑哧笑道：凤先，都说你的银戟天下无双，
奴家好想仔细看看嘛。 \n"NOR,

        WHT"\n纱影闪动，白面高冠之人腾身而起。 \n\n"NOR,

    	HIR"吕凤先剑眉轻挑，傲然冷笑道：受死吧。 \n"NOR,
    	
});


void event1(object me, int count)
{
	object lu, meihuadao;
	
	lu = present("lu fengxian", this_object());
	meihuadao = present("meihuadao",this_object());
	
	if (!lu || !meihuadao)	return;
	if (environment(me)!=this_object()) 	return;
		
	tell_object(me,event1_msg[count]+"\n");
	if(++count==sizeof(event1_msg))
	{
		lu->kill_ob(me);
		return;
	}
	else call_out("event1",1,me,count);
	return ;
}

void init()
{       
        add_action("do_answer","answer");
    
}

string *event2_msg=	({
	
	HIR"\n吕凤先突然嘶声悲鸣一声：为什么？为什么吕某浑身功力使不出一乘？ \n"NOR,
	
	HIR"吕凤先回过身，盯着床上的梅花盗，绝望地道：你，你？为什么？你出卖我？
难道你以为我不如上官金虹么？ \n"NOR,
	
	HIR"吕凤先似要奋力将银戟掷向梅花盗，但手一软，终于银戟哐当一声掉在地上。 \n"NOR,

	HIR"\n吕凤先无尽悲伤的苦笑一声：仙儿，我怎又舍得了你。。。 。 
一言未罢，吕凤先一手扶床，缓缓倒在白纱红血之中。 \n"NOR,

    	GRN"\n梅花盗轻摆腰肢，踢了踢吕凤先的尸身，斜靠在床上，讥笑道：这些臭男人，死不足惜。\n"NOR,
    	GRN"\n梅花盗忽又抬起头，美丽无暇的娇躯轻轻扭动，洁白的胸膛急速地起伏，只是看着你。 \n"NOR,
    	GRN"\n梅花盗只是微笑得看着你，她的确不用再说话。 \n"NOR,
    	GRN"\n她的眼睛在说话，她的微笑在说话，她的纤手，她的胸膛，她的腿……她身上的每寸
每分都在说话。\n"NOR,
    	
});


void event2(object me, int count)
{
	object lu, meihuadao, spear,*inv;
	int n;
	
	lu = present("lu fengxian", this_object());
	meihuadao = present("meihuadao",this_object());
	
	if (!meihuadao)	return;
	if (environment(me)!=this_object()) 	return;
		
	tell_object(me,event2_msg[count]+"\n");
	if (count == 3) {
		lu->set("die",1);
		if (spear = present("spear",lu)) 
			spear->move(this_object());
		else { inv = all_inventory(this_object());
		 	n = sizeof(inv);
		 	while (n--) {
		 		if (inv[n]->query("lu_spear"))
		 			spear = inv[n];
		 	}
		}
		if (!spear) {	
			spear = new (__DIR__"npc/obj/silver_spear");
			if (spear) spear->move(this_object());
		}
		spear->set("name","沾满鲜血的银戟");	
		lu->die();
	}
	if(++count==sizeof(event2_msg))
	{
		if (me->query("gender")=="男性") {
			tell_object(me, HIG"
你不禁心猿意马，只要是男人，自然懂得她说的“话”，你是愿意（answer accept）
还是拒绝（answer reject）？\n"NOR);
			me->set_temp("maze/jq1_answer",1);
		} else 	{
			tell_object(me,HIG"
虽然你身为女子，但看到如此娇媚的可人儿，不禁也心中踌躇，一股热流自下而上，
涌遍全身，是答应她（answer accept）还是拒绝（answer reject）呢？ \n"NOR);
			me->set_temp("maze/jq1_answer",2);
		}
		call_out("do_escape", 40, me, meihuadao);
		return;
	}
	else call_out("event2",1,me,count);
		
	return ;
}

int 	do_escape( object me, object meihuadao)	{
	message_vision("\n\n梅花盗咯咯一笑，“既然如此优柔寡断，就在屋外想好再来找奴家吧。” \n", me);
	tell_object(me, "你被一脚踢出了屋外。\n");
	me->stop_busy();
	me->move(__DIR__"jq1-exit");
	return 1;
}

int 	do_answer(string arg) {
	object me;
	object room, spear, meihuadao;
	me = this_player();
	if (!me->query_temp("maze/jq1_answer")) return 0;
	if (me->query_temp("maze/jq1_answer") == 1) {
		remove_call_out("do_escape");
		me->delete_temp("maze/jq1_answer");
		if (arg == "accept") {
			tell_object(me, HIY" 
你满目尽是梅花盗雪白的胸膛，双腿。。。心中还未决定，嘴里已结结巴巴道：我愿意。 
梅花盗“嘤咛”一声倒在你的怀里，一丝淡香袭来，两人已滚倒在洁白的纱海之中。 
绮丽的梦开始了。。。。 \n\n"NOR);
			me->set("maze/金钱一荤",1);
			me->ccommand("drop all");
			me->unconcious();
			room = find_object(AREA_FY"swind3");
			if (!room) room = load_object(AREA_FY"swind3");
			me ->move(room);
			me->stop_busy();
			return 1;
		}
		if (arg == "reject") {
			message_vision(HIW"
$N定住心神，心如止水，冷冷道：梅花盗，你祸害天下，你受死。。。 
话音未落，梅花盗咯咯笑了起来，美目流转，柔声道：既然如此，恕奴家就不久陪了。 
梅花盗纤手轻轻一拉床头纱绳，大床突然一翻，梅花盗瞬即消失得无影无踪。\n\n"NOR, me);
			me->stop_busy();
			if (meihuadao = present("meihuadao",this_object()))
				destruct(meihuadao);
			return 1;
		}
	}
	if (me->query_temp("maze/jq1_answer") == 2) {
		remove_call_out("do_escape");
		me->delete_temp("maze/jq1_answer");
		if (arg == "accept") {
			tell_object(me, HIY" 
你大脑一片空白，莲足轻挪，竟已坐到梅花盗怀中。。。 
梅花盗咯咯一笑：好妹妹，让姐姐叫你怎么做真正的女人。。。 
柔软的藕臂灵蛇一般缠上你的腰肢，胸口。。。 
绮丽的梦开始了。。。。  \n\n"NOR);
			me->set("maze/金钱一荤",1);
			me->ccommand("drop all");
			me->unconcious();
			room = find_object(AREA_QIANJIN"wting");
			if (!room) room = load_object(AREA_QIANJIN"wting");
			me ->move(room);
			me->stop_busy();
			return 1;
		}
		if (arg == "reject") {
			message_vision(HIW"
$N娇哼一声：姑奶奶可对你没半点兴趣，受死吧。。。 
话音未落，梅花盗咯咯笑了起来，美目流转，柔声道：既然如此，恕奴家就不久陪了。 
梅花盗纤手轻轻一拉床头纱绳，大床突然一翻，梅花盗瞬即消失得无影无踪。 \n\n"NOR, me);
			me->stop_busy();
			if (meihuadao = present("meihuadao",this_object()))
				destruct(meihuadao);
			return 1;
		}
	} 

	return 0;
}
		
   			