// TIE@FY3 ALL RIGHTS RESERVED
#include <ansi.h>
#include <skill.h>
inherit ROOM;
void create()
{
        set("short", "达摩洞内");
        set("long", @LONG
这是一个高宽不过九尺，长度不足二丈的天然石洞。方方的洞门，正好向阳敞
开，使得这里冬暖夏凉，空气清爽。洞中空无一物，只是地上有个蒲团状的圆石，
被磨得发光。不知道在达摩后还有多少高僧在这里面壁(ｍｉａｎｂｉ)过。
LONG
        );
	set("exits", ([ 
		"out" : __DIR__"damo",
	]));
//	set("no_fight", 1);
	set("in_mianbi", 0);
	set("coor/x",63);
	set("coor/y",26);
	set("coor/z",0);
	setup();
}
void init(){
	add_action("do_mianbi", "mianbi");
	add_action("do_look", "look");
	add_action("do_study", "study");
}

int do_study(string arg){
	object ob, me;
	mapping skill;
	string book, liter;
	int cost, sena;
	int amount=0;
	int my_skill;
	me = this_player();
    if( me->is_fighting() )
        return notify_fail("你无法在战斗中专心下来研读新知！\n");
    if( me->is_busy() )
        return notify_fail("你上一个动作还没有完成，不能研读新知。\n");

    if(!arg || sscanf(arg, "%s %d", book, sena)!=2 )
        return notify_fail("指令格式：study <物品> <神数量>\n");
    if(book != "print"){
    	return 0;
    }
    if(book == "print" 
		&& !REWARD_D->check_m_success( me, "少林面壁")) {
//    	&& !me->query("marks/少林_面壁成功")) {
		tell_object(me, "你什么都看不出来，怎么学呢？\n");
    	return 1;
    }
	ob = present("print", this_object());
    if(!objectp(ob))
    	return notify_fail("你要学什么？\n");
	return 0;
}     
	


int do_mianbi(){
	object me;
	me = this_player();

	if(me->is_fighting()){
		return notify_fail("战斗中不能面壁。\n");
	}
	if(me->is_busy()){
		return notify_fail("你正在忙！\n");
	}

	message_vision("$N盘腿坐在圆石上，眼睛聚精会神地看着石壁。\n", me);
	me->set_temp("disable_inputs", 1);
	me->add_temp("block_msg/all", 1);
	me->set_temp("is_unconious", 1);
	me->set("disable_type", HIG "<面壁中>"NOR);
	me->set_temp("in_mianbi", 1);
	me->start_call_out( (: call_other, __FILE__, "remove_mianbi", me :), 8 + random(10));
	return 1;	
}

void remove_mianbi(object me){
	object obj;
	int i;
	me->delete_temp("disable_inputs");
	me->delete("disable_type");
	if (me->query_temp("block_msg/all")>=1)
	    	me->add_temp("block_msg/all", -1);
	me->delete_temp("in_mianbi");
	me->delete_temp("is_unconcious");
	if (REWARD_D->check_m_success( me,"少林面壁")) {
//	if(me->query("marks/少林_面壁成功")) {
		tell_object(me, HIG"\n石壁上面隐隐约约显示出一个人像( ｐｒｉｎｔ）。\n"NOR);
		if(!present("damo print", this_object())){
			obj = new(__DIR__"npc/damo");
			obj->move(this_object());
		}
		return;
	}
	if(!me->query("marks/少林面壁")){
		tell_object(me,"你什么也感觉不出来。\n");
		return;
	}
	if(!random(5)){
		if(!me->query("marks/面壁领悟")){
			tell_object(me, "你觉得困了，禁不住闭上了双眼，朦胧中你仿佛听到有人在对话。\n"); 
			tell_object(me, "\n问：“欲修何法，即得解脱？”\n"); 
			tell_object(me, "答：“唯有顿悟一门，即得解脱。”\n"); 
			tell_object(me, "问：“云何为顿悟？”\n");
			tell_object(me, "答：“顿者，顿除妄念。悟者，悟无所得。”\n"); 
			tell_object(me, "问：“从何而修？”\n"); 
			tell_object(me, "答：“从根本修。“\n"); 
			tell_object(me, "问：“云何从根本修？”\n");
			tell_object(me, "答：“心为根本。”\n");
			tell_object(me, "\n你忽然一身冷汗，醒了过来，发现你自己原来还坐在圆石上。刚才 
的声音难道只是南柯一梦？\n");
			me->set("marks/面壁领悟", 1);
		} else if (me->query("marks/面壁领悟") == 1) {
			tell_object(me, "你觉得困了，禁不住闭上了双眼，朦胧中你仿佛听到有人在对话。\n"); 
			tell_object(me, "\n问：“云何解脱心？”\n"); 
			tell_object(me, "答：“无解脱心，亦无无解脱心，即名真解脱也。经云：法尚应舍，何况非法也。法者是有，
非法是无也。但不取有无，即真解脱。” \n");
			tell_object(me, "问：“云何得道？”\n"); 
			tell_object(me, "答：“以毕竟得为得。”\n"); 
			tell_object(me, "问：“云何是毕竟得？”\n"); 
			tell_object(me, "答：“无得无无得，是名毕竟得。”\n"); 
			tell_object(me, "问：“云何是毕竟空？”\n"); 
			tell_object(me, "答：“无空无无空，即名毕竟空。”\n"); 
			tell_object(me, "\n你睁开眼睛，一楞，发现并没有人在周围说话。\n"); 
			me->set("marks/面壁领悟", 2);
		} else if(me->query("marks/面壁领悟") == 2) {
			tell_object(me, "你觉得困了，禁不住闭上了双眼，朦胧中你仿佛听到有个低沉的而温和的声音在对你说：\n"); 
			tell_object(me, "谓修道行人，若受苦时，当自念言我从往昔无数劫中，弃本从末，流浪诸有，多起怨憎，\n");
			tell_object(me, "违害无限，今虽无犯，是我宿殃恶业果熟，非天非人所与，甘心忍受，都无冤诉。经云：\n");
			tell_object(me, "逢苦不忧，何心故，识达故，此心生时，与理相应，体冤进道，故说言报冤行。\n");	 
			tell_object(me, "\n你豁然惊醒，耳边余音未缭。忽然之间顿然开悟！\n"); 
			me->set("marks/面壁领悟", 3);
		}
		me->delete("marks/少林面壁");
		return;
	} 
	switch(random(3)){
		case 0:
			message_vision("$N嘘了口气。起来活动了一下手腿。\n", me);
		break;
		case 1:
			message_vision("$N挠了挠头，站了起来。\n", me); 
		break;
		case 2: 
			message_vision("$N揉了揉眼睛，好像在石壁上看到了什么，估计是眼花了。\n", me);
		break;
	}
}

int valid_leave(object obj, string dir){
	object room;
	room = find_object(__DIR__"damo");
	if(!objectp(room)){
		room = load_object(__DIR__"damo");
	}
	if(dir == "out" && present("guard monk", room)){
		if(obj->query("marks/少林面壁")){
			message_vision(YEL"洞外守护僧对$N说到：”这位师叔，方丈有令，命你在洞内面壁思过。。“\n"NOR, obj);
			message("vision", YEL"守护僧对着洞内说道：”这位师叔，方丈有令，命你在洞内面壁思过。。“\n"NOR, room);
			return 1;
		}
	}
	return 1;
}
