#include <ansi.h>
inherit ROOM;
string staff();
void create(){
    set("short", "蚩尤秘窟");
	set("long", @LONG
迷朦的天色到这里募然骤变，刹那间浓云翻滚，电闪雷鸣。在这人畜不至的森
罗鬼域里，赫然有十一尊大小不一的巨像。最大的高达百尺，雄伟狰狞，有顶天立
地之威，睥睨天下之势，竟然是上古传说的大神蚩尤；其余十座塑像，分别为蛮、
夷、戎、狄、黑、蛰、邪、兽、鬼，蚩尤统领的各部落首领，塑工古朴，年代久远，
每具塑像均向蚩尤顶礼膜拜。四周满山遍野皆是森森白骨，排列得整齐异常，头向
蚩尤巨像，虔诚膜拜。
LONG);
	set("staff", 1);
	set("type","street");
	set("exits",([
        "north":__DIR__"chiyoudao2",
	]) );
    set("objects",([
    ]) ); 
    set("item_desc", ([
            "法杖": (: staff :),
            "staff": (: staff :),
    ]) );
	setup();
}

/*
void init(){
	add_action("do_pull", "pull");
}

string staff(){
	object me;
	me = this_player();
	if(query("staff")){
		tell_object(me, YEL"\n
一柄由万载菩提木制成的法杖，一大半已深深插入蚩尤巨像头顶，但露出的一部分
依旧光华夺目，不知道是否能拔出来（pull)；据传上古时黄帝斩杀蚩尤巨凶后，
唯恐其亡魂不散，特向佛祖借来这万年菩提杖插入蚩尤石像，以镇住这不世之凶，
万世不得翻身。\n\n"NOR);
	} else {
		tell_object(me, "大神蚩尤像头顶的法杖已然不见，只剩一个空洞。\n");
	}
	return "";
}


int do_pull(string arg){
	object me, staff;
	int damage;
	me = this_player();
	if(!arg || (arg != "staff" && arg != "法杖")) {
		return notify_fail("你要拔什么？\n");
	}
	if(!query("staff")) {
		return notify_fail("已经没有法杖了。\n");
	}
	if(me->query("kee") < 100) {
		return notify_fail("你没有足够的气血。\n");
	}
	if(me->query("force_factor") > 80 && me->query_str() > 30 ) {
		message_vision("$N双手紧紧握住菩提法杖，牙关一咬，虎口鲜血迸射，怒喝一声：起！！\n", me);
		message_vision(HIY"\n菩提法杖突然放出万道金华，七色彩晕，山摇地动之间，法杖应声而起，冲天而出！\n"NOR,
				me);  
		set("long", @LONG
迷朦的天色到这里募地骤变，刹那间浓云翻滚，电闪雷鸣。在这人畜不至的森
罗鬼域里，赫然有十一尊大小不一的巨像。最大的巨像高达百尺，雄伟狰狞，有顶
天立地之威，睥睨天下之势，赫然便是上古传说的大神蚩尤；其余十座塑像，分别
为蛮、夷、戎、狄、黑、蛰、邪、兽、鬼，蚩尤统领的各部落首领，塑工古朴，看
起来年代久远，均向大像顶礼膜拜。而四周则满山遍野皆是森森白骨，但排列得整
齐异常，而每一具白骨均头向蚩尤巨像，俱在虔诚膜拜。
LONG
);
		set("staff", 0);
		me->start_busy(4);
		me->set_temp("marks/chiyou", 1);
		call_out("stone_fall", 3, me);
	} else {
		message_vision("$N双手紧紧握住菩提法杖，牙关一咬，虎口鲜血迸射，怒喝一声：起！！\n", me);
		message_vision("菩提法杖纹丝不动。\n", me);
		me->start_busy(4);
		damage = me->query("kee") / 5;
		me->receive_damage("kee", damage);
	}

	return 1;
}

void stone_fall(object me){
	object *all, *inv, room, obj;
	int i;
	string *names = ({"chiyoudao", "chiyoudao1", "chiyoudao2", "chiyoudao3", "chiyoudao4", "chiyoudao5",
			"chiyoudao6", "chiyoudao7", "chiyoudao8", "chiyoudao9"});
	
	all = all_inventory();
	message_vision("\n突然之间蚩尤秘窟有如天崩地裂般，浓云翻滚，电闪雷鸣，山石又如疾风暴雨般\n", me);	 
	message_vision("漫天砸下！\n", me); 
	message_vision("\n$N神色大变，奋起全力在乱石风暴中苦苦寻求一线生机。\n", me);
	for(i=0;i<sizeof(names);i++){
		if( obj = find_object(__DIR__+names[i])) {
		tell_object(obj,HIY "\n\n远方传来一阵隆隆巨响，紧跟着无数石块砸落了下来。\n\n"NOR);
		}
	}
	inv = filter_array(all, (: interactive($1) && !$1->query_temp("marks/chiyou") :));
	for(i=0; i<sizeof(inv); i++) {
		message_vision(HIY"$N被这突如其来的变化惊的目瞪口呆，只见无数巨石狠狠地砸了过来，\n"NOR, inv[i]);
		message_vision(HIY"当真是挡无可挡躲无可躲。\n"NOR, inv[i]);
		if(inv[i]->query_skill("dodge",1)>=150 && inv[i]->query_skill("parry",1)>=150){
			message_vision(HIG"\n在这间不容发的情况下$N躲过了巨石的攻击。\n"NOR, inv[i]);
		} else {
			tell_object(inv[i], "你左挡右躲向前奔跑期望躲过巨石的袭击。\n");
			me->start_busy(3);
			room = find_object(__DIR__"chiyoudao");
			if(!objectp(room)){
				room = load_object(__DIR__"chiyoudao");
			}
			inv[i]->move(room);		
			message_vision(RED"\n$N一个躲闪不及，无数巨石狠狠地砸了过来。。。\n"NOR, inv[i]); 
			inv[i]->unconcious();
		}
	}
	if(me->query_skill("dodge",1) >= 150 && me->query_skill("parry",1) >= 150 && random(100)){
		remove_call_out("chiyou");
		call_out("chiyou", 3, me);
	} else {
		tell_object(me, "你左挡右躲向前奔跑期望躲过巨石的袭击。\n\n");
		me->start_busy(3);
		room = find_object(__DIR__"chiyoudao");
		if(!objectp(room)){
			room = load_object(__DIR__"chiyoudao");
		}
		me->move(room);
		message_vision(RED"$N一个躲闪不及，无数巨石狠狠地砸了过来。。。\n"NOR, me); 
		if(!random(200)){
			me->die();
		} else {
			me->unconcious();
		}
	}
}

void chiyou(object ob){
	object chiyou;
	if(!interactive(ob) && environment(ob) != this_object()){
		return;
	}
	message_vision(HIB"\n漫天乱石中，狂风乍起，天色变得一片狰狞，仿佛无数厉鬼野兽在咆哮怒吼！\n"NOR, ob);
	message_vision(HIR"\n鲜红如血般的大火熊熊燃起，一片火海中升起一个高达百尺，有如天神般的巨汉！\n"NOR,ob); 
	message_vision(HIR"远处，近处，空气中每一处地方无数的凶灵邪兽齐声膜拜，狂呼！！\n\n"NOR, ob);
	message_vision(HIY"              －－不－世－战－神－－蚩－尤－重－生－－  \n\n"NOR, ob);
	chiyou = new(__DIR__"npc/chiyou");
	if(objectp(chiyou) && !present("chi you", this_object())){
		chiyou->move(this_object());
		chiyou->set("time",time());
	}else
		destruct(chiyou);
	chiyou->chiyou_call(ob); 	
}

//	Notice: part of the room reset is in /d/wolfmount/cliffroad3.

void reset(){
	object ob;
	::reset();
	if (ob=present("chi you",this_object())) 
	if (!ob->is_fighting()) {
		message_vision(CYN"\n乌云突然裂开道长缝，$N那庞大身躯冲上云霄，只留下他的狂笑声回荡不止。\n"NOR, ob);
		destruct(ob);
	}	
	
}

*/

int valid_leave(object obj, string dir){
	object ob;
	if(dir == "north" && (ob=(present("chi you", this_object())))){
		if (!ob->query("staff"))
			return notify_fail("蚩尤那庞大的身躯堵住了洞口。\n");
	} 
	return ::valid_leave(obj, dir);
}
