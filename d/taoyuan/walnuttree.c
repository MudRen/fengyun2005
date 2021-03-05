#include <ansi.h>
inherit __DIR__"no_killing_place";
#define MINAGE 16
#define MAXAGE 24
#define FATEMARK "宿命A/桃源_流星"
void create()
{
	set("short", "核桃树下");
	set("long", @LONG
靠近草地的边缘长着一棵枝叶繁茂的小树，树下是碧绿的草地，一块平整的大
石头压在草地上，几朵黄色的小花开在石头的旁边。夏日时一阵阵的小凉风吹来让
人暑意全消，是一个纳凉的好地方。
LONG
	);
	set("long_night", @LONG
脚下的绿草地细密柔软，在昏暗的夜光下你隐约可以看见一棵小树，每当晴朗
无云的夜晚，你站在树下透过茂密的枝叶，便可看见天上星光浮动。树下有一块平
坦的大石头。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
		"west" : __DIR__"lawn",
	]));

	set("item_desc", ([
		"stone" : "平坦的大石头，就象一个天然的大床，你可以躺下。（laydown/getup）\n",
		"大石" : "平坦的大石头，就象一个天然的大床，你可以躺下。（laydown/getup）\n",
	]) );
	set ("no_magic", 1);
	set("outdoors","taoyuan");
      	set("coor/x",50);
      	set("coor/y",-10);
	set("coor/z",0);
	setup();
}

void init(){
	::init();
	add_action("do_laydown", "laydown");
	add_action("do_getup","getup");
}

void init_scenery()
{
	remove_call_out("falling_star");
	call_out("falling_star", 1);
}

void add_fate_mark(object ob)
{
	int num = 1 + random(10);
	if(!random(4)) {
		message("vision", HIG"你在流星消逝前的刹那间许下了一个愿望！！\n"NOR, ob);
		message_vision("$N默默地站了起来！\n", ob);
		ob->set(FATEMARK, num);
		log_file("riddle/FATE_LOG",
			sprintf("%s(%s) 得到"+FATEMARK+" "+num+"。 %s \n",
				ob->name(1), geteuid(ob), ctime(time()) ));
	}
}


int do_laydown(){

	object me/*, walnut*/,who;
	int i, j;

	me = this_player();
	i = NATURE_D->get_season();
	j = random(20);

	who=query("laydown_person");

	if(me==who) return  notify_fail("你已经躺下了呀！\n");
	if(who&&present(who,this_object()))
		return notify_fail("已经有人躺在大石上了。。。\n");

	if(i == 1){
		message("vision", "春风吹在你的脸上让你睡意悠然，石头虽然有些凉却还可以忍受。\n"
				, me);
		message("vision", me->name() + "惬意地躺到了大石上。\n", this_object(), me);
		set("laydown_person",me);
	} else if(i == 2  ){
		if(NATURE_D->is_day_time()){
			message("vision", "小树的枝叶替你遮挡着阳光，你舒适的躺到大石上。\n", me);
			message("vision", me->name() + "惬意地躺到了大石上，舒服地叹了一口长气。\n",
					this_object(), me);
			set("laydown_person",me);
		} else {
			message("vision", "灿烂的星空是那么的迷人，你不禁悠然神往。\n", me);
/*			if(random(10)<1){
				remove_call_out("falling_star");
				call_out("falling_star", j, me);
			}
*/			message("vision", me->name() + "惬意地躺到了大石上。\n", this_object(), me);
			set("laydown_person",me);
		}		
	} else if(i == 3){
		message("vision", "秋高气爽，落叶凋零，躺在这里的你心中充满了感伤。\n", me);
		message("vision", me->name() + "躺下深深地叹了一口气，声音中充满了无奈。\n",
				this_object(), me);
		set("laydown_person",me);
	}
	else if(i == 4){
		message("vision", "冰凉的石头让你倏然一惊，你狠狠心硬是躺了下去。\n", me);
		message("vision", "刚躺到石头上的" + me->name() + "打了个冷战，差点没冻出病来。\n"
				, this_object(), me);
		set("laydown_person",me);
	}

	if(me->query("kar")> 16){
		if (!REWARD_D->riddle_check(me,"好生之德"))
			REWARD_D->riddle_set(me,"好生之德",1);
	    remove_call_out("walnut_fall");
	    call_out("walnut_fall", j, me);
	} else
		tell_object(me,"\n唉，人生的机遇没那么点小运气是碰不到的．．．．\n\n");
		
	return 1;
}

int do_getup()
{
	object me;

	me=this_player();
	if(me!=query("laydown_person")) return 0;
		remove_call_out("walnut_fall");
	message_vision("$N从大石上爬了起来。\n",me);
	delete("laydown_person");
	return 1;
}

int valid_leave(object who,string dir)
{
	if(who==query("laydown_person"))
		return notify_fail("你正躺着呢，要站起身来（getup）才能离开！！\n");
	return ::valid_leave(who,dir);
}

void walnut_fall(object me)
{
	tell_object(me,CYN"不知不觉地，你进入了甜甜的梦乡。。。。。。\n"NOR);
	 me->perform_busy(5);
	 call_out("walnut_fall2", 10, me);
}

string view(string room) {
//	int i;
	object /**inv,*/env;
//	mapping exits;
	string /*roomdesc,*/ str/*, *dirs*/;
	
	env = find_object(room);

	if(!env) env=load_object(room);	
	if (!env) env = load_object(AREA_HUANGSHAN"mroad1"); // Just in case someone removes a room.
	
	str = CYN"\n\n飘飘悠悠地，你来到了一个绿草如茵的幽静所在。。。。\n\n\n"NOR;
	
	// room descriptions.
	str += sprintf( "    %s \n",env->query("long"));
	
	str += RED " 一个细细小小的声音传来，似乎是谁在呼救。。。。\n\n\n"NOR;
	return str;
}

void walnut_fall2(object me)
{	
	string *rooms = ({ AREA_HUANGSHAN"mroad1", AREA_HUASHAN"shanlu",AREA_SONGSHAN"lianhua",
			AREA_OLDPINE"spath2", AREA_OLDPINE"spath3",
			AREA_EREN"road1",AREA_ZANGBEI"spring",AREA_EREN"orchard2"});
	string my_room;
	
	if (!stringp(my_room = me->query("marks/turtle_room")))
		my_room = rooms[random(sizeof(rooms))];
	me->set("marks/turtle_room",my_room);
	tell_object(me, view(my_room));
	me->perform_busy(3);
	call_out("walnut_fall3", 6, me);		
}


void walnut_fall3(object me)
{	
	object walnut;
	int num = 1 + random(10);	
	message_vision(WHT"风吹树动，一个青核桃落下正好砸到$N的头上。\n"NOR, me);
	message_vision(WHT"$N倏然一惊，一骨碌爬了起来。\n"NOR, me);
	if (!me->query("宿命B/桃源_核桃")) {
		me->set("宿命B/桃源_核桃", num);
		log_file("riddle/FATE_LOG",
			sprintf("%s(%s) 得到宿命B/桃源_核桃 "+num+"。 %s \n",
				me->name(1), geteuid(me), ctime(time()) ));
	}
	walnut = new(__DIR__"obj/walnut");
	walnut->move(this_object());
	delete("laydown_person");
}

void falling_star()
{
//	int i,age;
	object ob = this_object();
	object *ppls;
	function f=(:add_fate_mark:);
	message("vision", HIW"突然之间一道闪亮的银光划过夜空，消失在南边的天际。\n"NOR, ob);
	ppls=filter_array(all_inventory(ob),(:userp($1) && interactive($1) && $1->query("age")>=MINAGE && $1->query("age")<=MAXAGE && !$1->query(FATEMARK):));
	if(sizeof(ppls))
		map_array(ppls,f);
}
