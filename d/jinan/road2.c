// street2.c
#include <ansi.h>
#include <room.h>
inherit ROOM;
string bei();
void do_caolian1(int stage, object me, object obj);
void create()
{
  set("short","斜阳道");
  set("long",@LONG
绕过大明湖，往东北而行，便是一条宽敞的石板路，历经沧桑，石板早已坑坑
洼洼，道旁静静立的是三三两两的老槐树，远处那连绵不断的山峦便是东岳泰山了。
路旁的半人多高的杂草丛里似乎隐约有个石碑。 
LONG
  );
  set("exits",([
         "southwest":__DIR__"road1",
  		"northeast" : __DIR__"road",
               ]));
	set("item_desc", ([
		"shibei" : (: bei :),
		"石碑" : (: bei :),
	]));
	set("no_magic", 1);
	set("cleaned", 0);
    set("outdoors", "jinan");
	set("coor/x",60);
	set("coor/y",120);
	set("coor/z",0);
	setup();
}

void init(){
	add_action("do_kill", "kill");
}
int do_kill(string arg){
	object me;
	me = this_player();
	message_vision("你感到一股强烈的杀气来自草丛之中，不由得取消了杀人的念头。\n", me);	
	return 1;
}

string bei(){
	object me;
	me = this_player();
	if(!query("cleaned")) {
		tell_object(me, "这仿佛是块朝廷所立的石碑, 似乎已经多年无人照看。两尺余高的杂草覆\n");
		tell_object(me, "盖了碑面，你无法看清上面写了什么。你似乎可以清理一下（ｃｌｅａｎ）。\n");
		add_action("do_clean", "clean");
	} else {
		tell_object(me, "石碑上刻着\n\n"); 
		tell_object(me, RED"中兴全功至德圣神武文昭仁宪孝皇帝绍兴六年，湖北同京西路宣抚副使\n"NOR);
		tell_object(me, RED"岳飞大破金寇于此。 \n\n"NOR);
		tell_object(me, HIR"钦命蔡州府立\n"NOR); 
          if(me->query("class") == "official" 
          		&& REWARD_D->riddle_check(me,"纵横天下")==1){
       //   		&& me->query("marks/大名湖畔纵横天下") == 1){
			tell_object(me, "\n看到这里，你不禁神往当年岳武穆驰骋疆场的神勇。\n");
			message("vision", me->name()+"盯着面前的石碑似乎陷入了沉思。\n", environment(me), me);
			add_action("do_caolian", "caolian");
			me->start_busy(2);
			call_out("do_spear", 3, me);
		}
	}
	return "";
}
void do_spear(object me){
	if(environment(me) != this_object()) {
		return;
	} 
	if(me->query_skill("yue-spear",1) >= 120){	
		tell_object(me, CYN"蓦然惊醒，你心中感到一股动力忍不住想操练一番岳家中平枪法。（ｃａｏｌｉａｎ）\n"NOR); 
		me->set_temp("marks/caolian_yue", 1);
	} else {
		message_vision("$N长叹了一口气， 在石碑前长长一鞠。\n", me);
	}
}

int do_caolian(){
	object obj, me;
	me = this_player();
	if(!me->query_temp("marks/caolian_yue")) {
		return 0;
	}
	obj = me->query_temp("weapon");
	if(!obj){
		return notify_fail("你手中并没有长枪，怎么操练?\n");
	}
	if(obj->query("flag") == 25) {
		message_vision(HIC"$N口中吟道：「待从头收拾旧山河，朝天阙。」，手中" + obj->name() +"倒转，\n"NOR, me);
		message_vision(HIC"枪杆由下至上，直向前打去。\n"NOR, me); 
		me->start_busy(2);
		call_out("do_caolian1", 2, 1, me, obj);
	}else {
		tell_object(me, "你手中并没有长枪，怎么操练?\n");
	}
	return 1;
}

void do_caolian1(int stage, object me, object obj){
	if(environment(me) != this_object()){
		return;
	}
	if(stage == 1){
		message_vision(HIC"$N长叹道：「靖康耻，犹未雪，臣子恨，何时灭！」，手中" + obj->name() + "晃出无数枪影。\n"NOR, me);
		me->start_busy(2);
		call_out("do_caolian1", 2, 2, me, obj);
	} else if(stage == 2){
		message_vision(HIC"$N面带忧色，吟道：「三十功名尘与土。」枪身突转，向地面横扫。\n"NOR, me);
		me->start_busy(2);
		call_out("do_caolian1", 2, 3, me, obj);
	} else if(stage == 3){
		message_vision(HIC"$N一声清啸，「驾长车，踏破贺兰山缺。」，大踏步向前走来，手中"
				+obj->name() + "平平递出，哧哧作声。\n"NOR, me);
		me->start_busy(2);
		call_out("do_caolian1", 2, 4, me, obj);
	} else if(stage == 4){
		message_vision(HIC"$N低头吟哦：「八千里路云和月」，手中" + obj->name() + "凌空虚点，蓦地进步跟身，\n"NOR, me);
		message_vision(HIC"扫出一排枪影。\n"NOR, me);
		me->start_busy(2);
		call_out("do_caolian1", 2, 5, me, obj);
	} else if(stage == 5){
		message_vision(HIY"\n$N收起了手中的" + obj->name() + ", 擦了擦额头的汗水。 在石碑前长长一鞠。\n"NOR, me);
		tell_object(me, "你心中似乎还有一丝困惑无法解决。\n");
		REWARD_D->riddle_set(me,"纵横天下",2);
//		me->set("marks/操练岳家中平枪法", 1); 
	}
}

int do_clean(){
	object me, obj;
	me = this_player();
	obj = me->query_temp("weapon");
	if( !obj ) {
            return notify_fail("你空着手，怎么清除那柔韧的草？\n");
	}
	if( obj->query("flag") == 4){
		message_vision("$N用手中的" + obj->name() + "慢慢地割去了石碑前面的杂草。\n", me);
		tell_object(me, "石壁上的字迹慢慢显露出来。\n");
		me->start_busy(3);
		set("cleaned", 1);
		remove_action("do_clean", "clean");
	} else {
		tell_object(me, "你用来割草的东西不对吧？\n");
	}	
	return 1;
}

void reset(){
	::reset();
	set("cleaned", 0);
}
