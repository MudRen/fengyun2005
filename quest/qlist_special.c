/*	fy2005 introduces two new qlist
	Special Quest: qlist_special 和 Repeatable Quest: qlist_repeat
	
	Qlist_repeat 的要求：
	（1）每个quest本身都有变化，可以适应一定不同经验段，
	（2）可以有足够的NPC支持多人，
	（3）你自己做多了不会厌烦
	
	Qlist_special的要求
	（1）此类Quest不会在questd中被引用太多
	（2）有一定的导向作用，或者是一个趣味性的谜题
	（3）或者是不这么干就没人会做、会注意的东西
	
*/	

#include <ansi.h>
inherit SKILL;

mapping *quest = ({
	  
	([											// 目的： Let ppl know where to cure 属性
		"quest":	"竹林医隐",
		"long":		"天机老人说：风云城南的梅花林里有一位神医，你且去探探他的住所，虽说你
现在还无求于他，以后他可是你的大救星。不过，神医脾气古怪，没病没灾千
万不要去打扰他。",
		"short":	"到风云城南的梅林里去拜访神医",
		"owner":	"mei da",		
		"location":	"风云城外",		
		"duration":		600,			
		"cancel": 		-1,					
		"exp_l":		2,						
		"exp_h":		50,					
		"quest_type":	"special",		
	]),
	([											// 目的： improve unarmed
		"quest":	"金狮石锁",
		"long":		"天机老人说：你的臂力太弱，到金狮镖局的练武场里去锻炼锻炼。",
		"short":	"到金狮镖局的练武场里去举十下石锁",
		"owner":	"meng",		
		"location":	"风云城",		
		"duration":		600,				
		"cancel": 		-1,					
		"exp_l":		2,						
		"exp_h":		20,					
		"quest_type":	"special",		
	]),
	([											// 目的： improve move 
		"quest":	"金狮梅花桩",
		"long":		"天机老人说：你的身法太慢，到金狮镖局的练武场里去锻炼锻炼。",
		"short":	"到金狮镖局的练武场里去走十圈梅花桩",
		"owner":	"meng",		
		"location":	"风云城",		
		"duration":		600,			
		"cancel": 		-1,					
		"exp_l":		3,						
		"exp_h":		20,					
		"quest_type":	"special",		
	]),
	([											// 目的：teach "listen"
		"quest":		"铁雪侠隐",
		"long":			"天机老人道：风云中有一对神仙眷侣，号为铁雪双侠，你可知他们现在何处？",
		"short":		"找到铁雪侠侣",
		"owner":		"none",				
		"location":		"铁雪山庄",			
		"duration":		600,	
		"cancel": 		-1,				
		"difficulty":	0,				
		"exp_l":		2,				
		"exp_h":		30,			
		"quest_type":	"special",		
	]),	
	([											// 目的：riddle and books
		"quest":		"武当送饭",
		"long":			"天机老人道：武当小镇上的老妇人缺人"WHT"送饭"CYN"，你去帮个忙吧。",
		"short":		"替武当小镇上的老妇人送饭",
		"owner":		"old woman",				
		"location":		"武当山下",			
		"duration":		600,	
		"difficulty":	0,				
		"exp_l":		2,				
		"exp_h":		30,			
		"quest_type":	"special",		
	]),	
	([
		"quest":	"黄麻子赌博",				// 目的：FY feature
		"long":		"天机老人说：昨天去银钩赌场输惨了，乖孙儿你替爷爷去赢回点面子来。",
		"short":	"到银钩赌场胜一圈骰子",
		"owner":	"huang",		
		"location":	"风云城",		
		"duration":		1800,			
		"difficulty":	100,			
		"cancel": 		-1,
		"exp_l":		3,						
		"exp_h":		50,					
		"quest_type":	"special",		
	 ]),
/*	([											// 目的：提高literate
		"quest":	"对诗",
		"long":		"广场西北角的一幢小楼里忽然轰天价地暴了声彩，天机老人笑着说：“青云诗\n"
				"社新近来了个『诗呆子』酸秀才，你去和他对对诗吧，也不要光顾了学武功。",
				//	这是天机在交待任务时所说的话
		"short":	"到酸秀才处去对出三句古诗",	// 这是player用quest命令查询时看到的
		"owner":	"suan xiucai",				// quest的给出者，
		"location":	"青云诗社",					// 地点
		"cancel": 		100,	// cancel +100%.
		"duration":		1800,					// 时限
		"difficulty":	200,					// 难度，增加difficulty/100奖励
		"exp_l":		3,						// Quest 起始经验段
		"exp_h":		100,					// Quest 截至经验段	
		"quest_type":	"special",				// 类型（现在似乎没用）
	]),*/		
	([											// 目的：FY feature
		"quest":	"二十四点",
		"long":		"天机老人说：东城私塾学堂的先生正在出考题呢，去试试看。",
		"short":	"到私塾先生那儿去完成两道考题",
		"owner":	"sishu",		
		"location":	"风云城",		
		"duration":	900,	
		"cancel": 		-1,			
		"difficulty":	200,			
		"exp_l":		3,						
		"exp_h":		100,					
		"quest_type":	"special",		
	]),
	([											// 目的： improve move (60-75)
		"quest":	"清平梅花桩",
		"long":		"天机老人说：你的身法还是不行，到清平山庄的练武场里去锻炼锻炼。",
		"short":	"到清平山庄的练武场里去走十圈梅花桩",
		"owner":	"meng",		
		"location":	"清平山庄",		
		"duration":	600,			
		"cancel": 		-1,					
		"exp_l":		10,						
		"exp_h":		30,					
		"quest_type":	"special",		
	]),
	([											// 目的： a chance to get salt
		"quest":	"新疆装盐",
		"long":		"天机老人说：新疆艾丁湖盐场正缺人干活，你去赚点零花钱吧。",
		"short":	"到新疆艾丁湖盐场找李豹干活",
		"owner":	"saltboss",		
		"location":	"新疆",		
		"duration":		900,			
		"difficulty":	0,		
		"cancel": 		-1,					
		"exp_l":		10,						
		"exp_h":		30,					
		"quest_type":	"special",		
	]),
	([											// 目的： teach riddle-solving
		"quest":	"竹林侠隐",
		"long":		"天机老人说：风云城北的竹林里据说有高人隐居，你且去探个究竟，那竹林机
关重重惑人耳目，记住，需要多听多看方能全身而退。",
		"short":	"到风云城北的竹林里去听听有什么动静",
		"owner":	"none",		
		"location":	"风云城外",		
		"duration":		600,			
		"cancel": 		-1,					
		"exp_l":		10,						
		"exp_h":		50,					
		"quest_type":	"special",		
	]),
	([											// 目的：riddle
		"quest":		"城隍黑影",
		"long":			"天机老人道：城里的薛陀子穷困潦倒，你去看看能不能"YEL"施舍"CYN"他些什么。",
		"short":		"到风云城里的薛陀子那里去看看帮帮他",
		"owner":		"none",				
		"location":		"风云城",	
		"duration":		900,			
		"difficulty":	0,	
		"cancel": 		0,				
		"exp_l":		40,				
		"exp_h":		70,			
		"quest_type":	"special",		
	]),
	([											// 目的：riddle
		"quest":		"白云揽胜",
		"long":			"天机老人道：近期南海风浪见小，去旅游胜地白云岛的航船重新开始营运了，
只可惜近期老夫实在抽不开身，你去代我去那里转上一转吧。",
		"short":		"到白云城去逛逛",
		"owner":		"none",				
		"location":		"白云",	
		"cancel": 		-1,					
		"duration":		900,			
		"difficulty":	0,				
		"exp_l":		30,				
		"exp_h":		100,			
		"quest_type":	"special",		
	]),	
	([											// 目的: riddle			
		"quest":	"武当大汉",
		"long":		"天机老人说：武当山下小镇里有个小媳妇儿遇到点"YEL"难事"CYN"，你去帮帮她吧。",
		"short":	"替武当山下小镇的小媳妇儿解难",
		"owner":	"dahan",		
		"location":	"武当山",		
		"duration":	900,			
		"cancel": 		0,			
		"difficulty":	100,			
		"exp_l":		40,						
		"exp_h":		70,					
		"quest_type":	"special",		
	]),
	([											// 目的：riddle
		"quest":	"五行铜人",
		"long":		"天机老人沉思道：人传兴国禅寺机关重重，更有一铜人镇守内寺通道，
你可速去勘查，若有线索即刻回报。",
		"short":	"到兴国禅寺，过五行铜人",
		"owner":	"none",				
		"location":	"兴国禅寺",			
		"cancel": 		-1,			
		"duration":		900,			
		"difficulty":	100,				
		"exp_l":		50,				
		"exp_h":		60,			
		"quest_type":	"special",		
	]),
	([											// 目的：My funny BIG mouse, and riddle solving
		"quest":	"金狮大厨",
		"long":		"天机老人说：金狮镖局的大厨正要人"YEL"帮忙"CYN"，你去磨练磨练，记住，要有耐心。",
		"short":	"到金狮镖局的大厨那儿帮忙",
		"owner":	"huang",		
		"location":	"风云城",		
		"cancel": 	-1,	// Cant cancel.
		"duration":		600,			
		"difficulty":	200,			
		"cancel": 		0,			
		"exp_l":		30,						
		"exp_h":		100,					
		"quest_type":	"special",		
	]),
	([											// 目的: riddle
		"quest":	"武当大水牛",
		"long":		"天机老人说：武当山下的放牛娃的牛病了，你去替他治治吧。",
		"short":	"替武当山下的放牛娃找出牛生病的原因",
		"owner":	"little farmer",		
		"location":	"武当山",		
		"duration":	900,			
		"cancel": 		-1,			
		"difficulty":	100,			
		"exp_l":		75,						
		"exp_h":		120,					
		"quest_type":	"special",		
	]),
	([											// 目的：riddle
		"quest":	"帮助孤独美",
		"long":		"天机老人急切道：刚收到孤独美的信鸽，他正被困于关外原始森林中，
你速速前去助一臂之力。",
		"short":	"到关外森林帮助孤独美脱困",
		"owner":	"none",				
		"location":	"关外",			
		"duration":		900,			
		"difficulty":	0,
		"cancel": 		-1,							
		"exp_l":		80,				
		"exp_h":		120,			
		"quest_type":	"special",		
	]),	
	([											// 目的：riddle
		"quest":	"黑松救美",
		"long":		"天机老人急道：风云东城外村民来报，黑松山匪徒又下山劫财伤命，你
可速去探个究竟，若村民有难需极力救助。",
		"short":	"黑松救美",
		"owner":	"none",				
		"location":	"黑松堡",			
		"duration":		900,		
		"cancel": 		-1,				
		"difficulty":	100,				
		"exp_l":		80,				
		"exp_h":		120,			
		"quest_type":	"special",		
	]),		
		([											// 目的：riddle
		"quest":		"探恶人谷",
		"long":			"天机老人对你说道：恶人谷，乃是天下恶人聚集之地。那些人
没有一个不是十恶不赦、满手血腥、被江湖人恨之人，但那许多恶人聚在一起，也没有人
敢走近恶人谷一步。你就做先锋去为江湖人探上一探。",
		"short":		"探明恶人谷虚实",
		"owner":		"none",				
		"location":		"恶人谷",
		"cancel": 		-1,					
		"duration":		900,			
		"difficulty":	0,				
		"exp_l":		100,				
		"exp_h":		150,			
		"quest_type":	"special",		
	]),			
	([											// 目的：riddle
		"quest":	"白云喜筵",
		"long":		"天机老人笑道：昆仑山白云山庄袁秋云的儿子今天娶亲，你混进去凑凑热闹吧。",
		"short":	"混入白云山庄的喜筵内",
		"owner":	"none",				
		"location":	"昆仑山",			
		"duration":		900,			
		"difficulty":	0,
		"cancel": 		-1,							
		"exp_l":		100,				
		"exp_h":		200,			
		"quest_type":	"special",		
	]),	
	([											// 目的: riddle
		"quest":		"巧熬鱼汤",
		"long":			"天机老人说：据说沉香镇的当归补血鱼汤远近闻名，你能不能去学做一个？",
		"short":		"做一份当归补血鱼汤",
		"owner":		"medman",		
		"location":		"沉香镇",		
		"duration":		900,			
		"cancel": 		-1,			
		"difficulty":	100,			
		"exp_l":		100,						
		"exp_h":		300,					
		"quest_type":	"special",		
	]),
	([											// 目的：riddle
		"quest":	"巧过白石",
		"long":		"天机老人道：风云东城外山里有个地方叫帝王谷，据说机关重重，又据
说谷里有处奇怪的地方叫白石，你可速去察看察看。",
		"short":	"到帝王谷白石处察看",
		"owner":	"none",				
		"location":	"帝王谷",			
		"duration":		900,			
		"cancel": 		1,			
		"difficulty":	0,				
		"exp_l":		200,				
		"exp_h":		450,			
		"quest_type":	"special",		
	]),	
	([											// 目的：riddle
		"quest":		"长春迷宫",
		"long":			"天机老人道：昔年铁中棠重振铁血大旗门后，夜帝父子和大旗门中的一位叫赤足汉
的前辈远游海外。近日江湖传闻夜帝隐在长春岛迷宫之后，不知真伪，你去长春岛探探虚实吧。
东海之滨，只要吹声哨，我的人自然会送你去长春岛。",
		"short":		"走过长春岛的地下迷宫见到夜帝",
		"owner":		"none",				
		"location":		"长春岛",			
		"duration":		900,			
		"difficulty":	100,			
		"cancel": 		-1,				
		"exp_l":		200,				
		"exp_h":		600,			
		"quest_type":	"special",		
	]),									
	([											// 目的：riddle
		"quest":	"智入岱庙",
		"long":		"天机老人忧心忡忡道：魔教主力聚集于泰山岱庙，意图不明，你可伺
机混入其中，探得其虚实后速来回报。",
		"short":	"到岱庙勘探地形",
		"owner":	"none",				
		"location":	"岱庙",			
		"duration":		1200,			
		"difficulty":	100,			
		"cancel": 		-1,				
		"exp_l":		300,				
		"exp_h":		350,			
		"quest_type":	"special",		
	]),	
	([											// 目的：riddle
		"quest":	"神水探幽",
		"long":		"天机老人道：据说清平剑客白三空退隐神水宫中，不知是虚是实，你
可速去探个究竟。",
		"short":	"设法进入神水宫",
		"owner":	"none",				
		"location":	"神水",			
		"duration":		900,			
		"difficulty":	100,
		"cancel": 		-1,							
		"exp_l":		300,				
		"exp_h":		350,			
		"quest_type":	"special",		
	]),	
	([											// 目的：riddle
		"quest":		"千金暗舱",
		"long":			"天机老人皱眉道：城里的千金楼歌舞升平，却是藏垢积污之地，更传楼里
私设暗牢，逼良为娼，你速去查个究竟。
天机老人看了看你说，凭你这两下子，恐怕还不是他们对手，记住，
打不过，就跑。",
		"short":		"探明千金楼的底细",
		"owner":		"none",				
		"location":		"千金楼",
		"cancel": 		-1,						
		"duration":		900,			
		"difficulty":	100,				
		"exp_l":		400,				
		"exp_h":		450,			
		"quest_type":	"special",		
	]),	
	([											// 目的：riddle
		"quest":		"勇闯蝙蝠岛",
		"long":			"天机老人皱眉道：听说在东海上有一个比常春岛更神秘和邪恶的地方，叫蝙蝠岛，
之前派去的探子，没有几个活着回来的，凭你的两下子，恐怕也。。。只是最近人手短缺，
你且代老夫前去探上一探。无须深入岛中，只需摸清路线就行。",
		"short":		"勇闯蝙蝠岛",
		"owner":		"none",				
		"location":		"到蝙蝠岛上探明岛上的虚实",			
		"duration":		900,			
		"difficulty":	200,				
		"cancel": 		-1,			
		"exp_l":		450,				
		"exp_h":		530,			
		"quest_type":	"special",		
	]),	
	([											// 目的：riddle
		"quest":		"探老云寨",
		"long":			"天机老人皱眉道：泰山老云寨匪徒屡屡下山抢劫，须有人去探个虚实才好，
天机老人看了看你说，凭你这两下子，恐怕还不是他们对手，记住，
打不过，就跑。（记住到幽灵山庄先去拿个竹管哦）",
		"short":		"探明老云寨虚实",
		"owner":		"none",				
		"location":		"泰山",	
		"cancel": 		-1,					
		"duration":		900,			
		"difficulty":	200,				
		"exp_l":		500,				
		"exp_h":		750,			
		"quest_type":	"special",		
	]),	
	([											// 目的：riddle
		"quest":		"探饿虎岗",
		"long":			"天机老人皱眉道：饿虎岗匪徒屡屡下山抢劫，须有人去探个虚实才好，
天机老人看了看你说，凭你这两下子，恐怕还不是他们对手，记住，
要斗智不斗力。",
		"short":		"探明饿虎岗虚实",
		"owner":		"none",				
		"location":		"饿虎岗",
		"cancel": 		-1,						
		"duration":		900,			
		"difficulty":	0,				
		"exp_l":		500,				
		"exp_h":		700,			
		"quest_type":	"special",		
	]),	
	([											// 目的: riddle
		"quest":		"义助陶氏",
		"long":			"天机老人说：边城赶车陶保义的媳妇忽然生了重病，你去想想办法吧。",
		"short":		"替陶保义的媳妇治病",
		"owner":		"sickman",		
		"location":		"边城",		
		"duration":		1200,					
		"difficulty":	100,			
		"exp_l":		500,						
		"exp_h":		1500,					
		"quest_type":	"special",		
	]),
	([											// 目的: learn how to use "answer", learn 边城声誉
		"quest":		"情深似海",
		"long":			"天机老人说：你知道边城翠浓的事了么？她太可怜了，你去帮帮她吧，
如果你没听说过，那么去问问别人，好好体会这过程对你将来解谜大有帮助。",
		"short":		"帮助边城的翠浓",
		"owner":		"cuinong",		
		"location":		"边城",		
		"difficulty":	100,	
		"duration":		1200,				
		"exp_l":		500,						
		"exp_h":		1500,					
		"quest_type":	"special",		
	]),	
	([											// 目的：riddle
		"quest":	"见陆小风",
		"long":		"天机老人道：魔教的松竹梅三长老整天在我这儿转悠，那四条眉毛的陆
小风不知又去了那里，你快去把他找到。",
		"short":	"到万梅山庄找到陆小风",
		"owner":	"none",				
		"location":	"万梅山庄",			
		"cancel": 		-1,			
		"duration":		900,			
		"difficulty":	100,				
		"exp_l":		600,				
		"exp_h":		650,			
		"quest_type":	"special",		
	]),		
	([	
		"quest":	"勘探水质",
		"long":		"天机老人说：眉峰聚的陆老板正为他的茶水水质发愁，你去看看吧。",
		"short":	"去陆羽处打听水质的事儿",
		"owner":	"lu yu",		
		"location":	"风云城",		
		"duration":		900,			
		"difficulty":	100,			
		"exp_l":		1000,						
		"exp_h":		2000,					
		"quest_type":	"special",		
	]),
		([	
		"quest":	"山珍海味",
		"long":		"天机老人说：恶人村的哈老板最近生意不好，你能去帮他的忙么？",
		"short":	"去哈哈儿处看有没有什么可帮忙的",
		"owner":	"haha er",		
		"location":	"恶人村",		
		"duration":		1800,			
		"difficulty":	200,			
		"exp_l":		1000,						
		"exp_h":		1500,					
		"quest_type":	"special",		
	]),
	([											// 目的：riddle
		"quest":		"龙虎寨虚实",
		"long":			"天机老人皱眉道：藏北龙虎寨匪徒屡屡下山抢劫，须有人去探个虚实才好，
天机老人看了看你说，凭你这两下子，恐怕还不是他们对手，记住，
打不过，就跑。",
		"short":		"探明龙虎寨虚实",
		"owner":		"none",				
		"location":		"藏北",	
		"cancel": 		-1,					
		"duration":		900,			
		"difficulty":	100,				
		"exp_l":		1500,				
		"exp_h":		2500,			
		"quest_type":	"special",		
	]),	
	([											// 目的：riddle
		"quest":		"司马小烟",
		"long":			"天机老人皱眉道：恶人村的小烟突然失踪了，你去查一查是怎么回事儿。",
		"short":		"到恶人村找到小烟的下落",
		"owner":		"none",				
		"location":		"藏北",	
		"cancel": 		-1,					
		"duration":		900,			
		"difficulty":	100,				
		"exp_l":		4000,				
		"exp_h":		5000,			
		"quest_type":	"special",		
	]),	
	([											// 目的：FY feature
		"quest":	"查猛护镖",
		"long":		"天机老人说：金狮镖局总镖头查猛正在找人护镖，你快去看看吧。",
		"short":	"替金狮镖局护一次镖",
		"owner":	"meng",		
		"location":	"风云城",		
		"cancel": 		0,			
		"duration":		2700,			
		"difficulty":	400,			
		"exp_l":		1200,						
		"exp_h":		5000,					
		"quest_type":	"special",		
	]),		
		([											// 目的：riddle
		"quest":		"义助宋福贵",
		"long":			"天机老人皱眉道：边城宋福贵的货物又被龙虎寨的匪徒抢了，
天机老人看了看你说，你学艺有成，当锄强扶弱，去，去找宋福贵。",
		"short":		"铲除龙虎寨匪患",
		"owner":		"none",				
		"location":		"藏北",				
		"duration":		1800,			
		"difficulty":	400,				
		"exp_l":		4500,				
		"exp_h":		5500,			
		"quest_type":	"special",		
	]),	
/*	([											// 目的：riddle
		"quest":		"明霞山阴",
		"long":			"天机老人皱眉道：城东明霞山阴之处，怨魂云集，老夫本委托了痕师太前去超度，
只恨近日道路阻塞，现需另觅他径。看你修为不错，且去探上一探？山阴之处，阴气极盛，
只怕还有什么邪道法器作崇，你自己需得小心。",
		"short":		"到了痕师太处询问超度之事",
		"owner":		"none",				
		"location":		"明霞山",			
		"duration":		900,			
		"difficulty":	0,			
		"cancel": 		-1,				
		"exp_l":		5000,				
		"exp_h":		5200,			
		"quest_type":	"special",		
	]),	*/
	([
		"quest":	"沉萼落香",
		"long":		"天机老人说：嗯，最近没有什么事给你，聊聊天，休息休息吧。",
		"short":	"发呆三分钟后向天机老人"YEL"汇报"NOR,
		"owner":	"none",		
		"location":	"任意地点",		
		"cancel": -1,	// Cant cancel.
		"duration":		200,			
		"difficulty":	0,			
		"exp_l":		10,						
		"exp_h":		10000,					
		"quest_type":	"special",		
	]),
});


mapping query_quest(int exp)
{
	int i, total;
	int *num = ({});
		
	total = sizeof(quest);
			
	for (i= 0; i< total; i++)	{
		if ( quest[i]["exp_l"] > exp ) continue;
		if ( quest[i]["exp_h"] < exp ) continue;
		num += ({ i });
	}
//	    CHANNEL_D->do_sys_channel("sys", sprintf("%O\n",num) );	    
	
	if (!sizeof(num))    return 0;
		
	return quest[num[random(sizeof(num))]];
}
        
        
int TotalNumber()
{
	return sizeof(quest);
}
