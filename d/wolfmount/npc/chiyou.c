inherit NPC;
#include <ansi.h>

void growup();

void create()
{
	set_name("蚩尤巨像", ({ "chi you", "chiyou" }) );
	set("race", "野兽");
	set("gender", "雄性");
	set("class","wolfmount");
	set("age", 10000);
	set("long", "蚩尤，与黄帝涿鹿中原的一代大神，鬓如剑戟，头有利角，铜头铁额，诛杀 
无道，乃古往今来睥睨天下之第一凶魔！他的头顶，有一根放射出万道金华
的[37m法杖[32m没顶而插\n");
	set("title", "不世战神");
	set("nickname", HIR"万古凶魔"NOR);
	set("NO_KILL","你无法攻击一具石像。\n");
	set("spawn_location","/d/wolfmount/chiyouku");
		
	set("str", 90);
  set("force_factor",100);
	set("cor", 100);
	set("per", 1);
	
	set("boss",1);
	set("big_boss",1);
	set("max_kee", 300000);
	set("max_gin", 300000);
	set("max_sen", 300000);
	
	set("limbs", ({ "头部", "身体", "爪子" }) );
	set("verbs", ({ "bite", "claw" }) );
	
	set("chat_chance_combat", 100);
    set("chat_msg_combat", ({
       	(: growup() :),
  }) ); 
	
	set_skill("unarmed", 700);
	set_skill("iron-cloth", 200);
	set_skill("yiqiforce", 100);
	set_skill("dodge", 400);
	set_skill("force",100);
	set_skill("parry", 400);
	set_skill("wolf-curse",200);
	set_skill("cursism",200);
	set_skill("summonwolf",300);
	set_skill("perception",400);
	map_skill("unarmed","yiqiforce");
	map_skill("cursism","wolf-curse");
	map_skill("force","yiqiforce");
	
	set("combat_exp", 13000000);
  set("staff",1);              
  set_temp("apply/attack", 200);
  set_temp("apply/dodge", 200);
	setup();

}

void init() {
	::init();
	if (query("staff"))
		add_action("do_pull", "pull");
	if (interactive(this_player()) && !query("NO_KILL"))
		kill_ob(this_player());	
		this_player()->kill_ob(this_object());
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
	set("long", "蚩尤，与黄帝涿鹿中原的一代大神，鬓如剑戟，头有利角，铜头铁额，诛杀 
无道，乃古往今来睥睨天下之第一凶魔！\n");
		set("staff", 0);
		me->perform_busy(4);
		call_out("stone_fall", 3, me);
	} else {
		message_vision("$N双手紧紧握住菩提法杖，牙关一咬，虎口鲜血迸射，怒喝一声：起！！\n", me);
		message_vision("菩提法杖纹丝不动。\n", me);
		me->perform_busy(4);
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
	
	all = all_inventory(environment(this_object()));
	
	message_vision("\n突然之间蚩尤秘窟有如天崩地裂般，浓云翻滚，电闪雷鸣，山石又如疾风暴雨般\n", me);	 
	message_vision("漫天砸下！\n", me); 
	message_vision("\n$N神色大变，奋起全力在乱石风暴中苦苦寻求一线生机。\n", me);
	for(i=0;i<sizeof(names);i++){
		if( obj = find_object(__DIR__+names[i])) {
		tell_object(obj,HIY "\n\n远方传来一阵隆隆巨响，紧跟着无数石块砸落了下来。\n\n"NOR);
		}
	}
	
	inv = filter_array(all, (: interactive($1):));
	for(i=0; i<sizeof(inv); i++) {
		message_vision(HIY"$N被这突如其来的变化惊的目瞪口呆，只见无数巨石狠狠地砸了过来，\n"NOR, inv[i]);
		message_vision(HIY"当真是挡无可挡躲无可躲。\n"NOR, inv[i]);
		if(inv[i]->query_skill("dodge",1)>=150 && inv[i]->query_skill("parry",1)>=150){
			message_vision(HIG"\n在这间不容发的情况下$N躲过了巨石的攻击。\n"NOR, inv[i]);
		} else {
			tell_object(inv[i], "你左挡右躲向前奔跑期望躲过巨石的袭击。\n");
			me->perform_busy(3);
			room = find_object(AREA_WOLFMOUNT"chiyoudao");
			if(!objectp(room)){
				room = load_object(AREA_WOLFMOUNT"chiyoudao");
			}
			message_vision(RED"\n$N一个躲闪不及，无数巨石狠狠地砸了过来。。。\n"NOR, inv[i]); 
			inv[i]->move(room);		
			inv[i]->unconcious();
		}
	}
	
	remove_call_out("chiyou");
	call_out("chiyou", 3, me);
	
}

void chiyou(object ob){
	object *all, *inv;
	int i;
	
	if(!interactive(ob) && environment(ob) != this_object()){
		set("staff",1);
		return;
	}
	message_vision(HIB"\n漫天乱石中，狂风乍起，天色变得一片狰狞，仿佛无数厉鬼野兽在咆哮怒吼！\n"NOR, ob);
	message_vision(HIR"\n鲜红如血般的大火熊熊燃起，一片火海中升起一个高达百尺，有如天神般的巨汉！\n"NOR,ob); 
	message_vision(HIR"远处，近处，空气中每一处地方无数的凶灵邪兽齐声膜拜，狂呼！！\n\n"NOR, ob);
	message_vision(HIY"              －－不－世－战－神－－蚩－尤－重－生－－  \n\n"NOR, ob);
	
	delete("NO_KILL"); 	
	set("name","蚩尤");
	
	all = all_inventory(environment(this_object()));
	inv = filter_array(all, (: interactive($1):));
	for(i=0; i<sizeof(inv); i++) {
		kill_ob(inv[i]);
		inv[i]->kill_ob(this_object());
		}
}


void growup(){
		
		object staff;
		ccommand("exert npc_hurtless");
		
		if (!query("claw_set")) {
			if (!random(5)){
				staff=new(__DIR__"obj/wolf-fist");
				staff->move(this_object());
				staff->wield();
				staff->set("nodrop_weapon");
				set("claw_set",2);
			}	
			else
				set("claw_set",1);
		}
		
		if (query("timer/cy_curse")+ 30 + random(20) < time() && query("kee")*100/query("max_kee")<90
			&& sizeof(query_enemy())>1){
			delete("timer/pfm/wm_mindcurse");
			ccommand("curse mindcurse");
			stop_busy();
			if (!random(3) && sizeof(query_enemy())>2) {
				delete("timer/pfm/wm_mindcurse");
				ccommand("curse mindcurse");
				stop_busy();
			}
			ccommand("xiao");
			set("timer/cy_curse",time());
		}
		
		return;
}			
		
/*
void chiyou_call(object ob){
	if(ob->query("marks/wolfmount_chiyou_kneel")){
		message_vision(CYN"$N仰天发出令人心胆俱裂的震天怒吼，山石雨下，乌云翻滚！\n"NOR, this_object()); 
		message_vision(CYN"万道血光之间，乌云突然裂开道长缝，$N那庞大身躯冲上云霄。。。\n"NOR, this_object());
		message_vision(CYN"四下归于死一般的寂静。。\n"NOR, this_object());
		destruct(this_object());
	} else { 
		message_vision(HIG"$N仰天发出令人心胆俱裂的震天怒吼，山石雨下，乌云翻滚！\n"NOR, this_object()); 
		message_vision(RED"\n$N微微低首，散发着无穷杀机的血色赤眸盯着$n一字字道：蚩尤重生，君临天下！\n"NOR, this_object(),ob); 
		message_vision(RED"汝等怯懦人兽，还不匍地臣服！（kneel or reject）\n"NOR, this_object()); 
	}
}

int do_kneel(){
	object me;
	me = this_player();
	tell_object(me, YEL"你只觉身陷无边的火海和恐惧之中，双膝一弯，五体匍地，诚惶诚恐膜拜道：战神重生，君临天下！\n"NOR);
	message("vision", YEL""+me->name() + "双膝一弯，五体匍地，诚惶诚恐膜拜道：战神重生，君临天下！\n"NOR,
			environment(me), me);
	if(query("busy") || this_object()->is_fighting()){
		return notify_fail(WHT"蚩尤正忙，没有时间理你。\n"NOR);
	}
		message_vision(RED"\n$N血眸精光四射，狂笑半晌道：不错，某先去天界找那轩辕帝出出这万世不得\n"NOR,this_object()); 
		message_vision(RED"翻身的晦气。嘿～，轩辕老鬼！ 万道血光之间，乌云突然裂开道长缝，蚩尤那庞\n"NOR, this_object()); 
		message_vision(RED"大身躯冲上云霄。。。 四下归于死一般的寂静。。\n", this_object()); 
	destruct(this_object());
	return 1;
}

int do_reject(){
	object me;
	me = this_player();
	set("busy", 1);
	message_vision(HIG"$N弹衣而起，仰天长笑道：纵使血溅于此，万劫不复，也绝不屈膝半寸！\n"NOR, me); 
	message_vision(HIR"\n$N双眸血光暴起，喝道：顺我者昌，逆我者～～亡～！\n"NOR, this_object()); 
	me->kill_ob(this_object());
	kill_ob(me);
	return 1;
}
*/



void die(){
	object me,staff;
	object owner,room;
	mapping hate;
	object *ppl, *ppl_present;
	int i;
	
	message_vision(HIR"\n$N嘶叫道：“可恶的。。。。我会再回来的。”"NOR, this_object());
	message_vision(HIR"$N那庞大身躯突然化为一股浓烟消失不见了。\n"NOR, this_object());
	
	if(objectp(me=query_temp("last_damage_from") ))     
        if(owner=me->query("possessed")) {
		me = owner;
	} 
    
  if (me) {
       	hate = query_hate_list();
	    if (sizeof(hate))
	    	ppl = keys(hate);
	    CHANNEL_D->do_sys_channel("sys",sprintf("ppl is %O\n",ppl));	
	    if (sizeof(ppl)) {	    
       		ppl_present=filter_array(ppl,(:objectp($1) && userp($1) && environment($1)==environment():));
	    }
	    CHANNEL_D->do_sys_channel("sys",sprintf("ppl_present is %O\n",ppl_present));
	    if (sizeof(ppl_present)) 
	    for (i=0;i<sizeof(ppl_present);i++) 	
	        REWARD_D->riddle_done(ppl_present[i], "力斩凶魔", 100, 1);   
	}
    
	if (me) 
		CHANNEL_D->do_sys_channel("info",sprintf("%s，%s于蚩尤秘窟击杀蚩尤。", NATURE_D->game_time(),me->query("name")) ); 
	
	seteuid(getuid());
	
	staff=new(__DIR__"obj/tigersoul");
	staff->move(environment(this_object()));
			
	if (query("claw_set")==2) {
		staff=new(__DIR__"obj/wolf-fist");
		staff->move(environment(this_object()));
	}
	
	destruct(this_object());
}


