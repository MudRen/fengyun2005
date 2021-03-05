/*	fy2005 introduces two new qlist
	Special Quest: qlist_special 和 Repeatable Quest: qlist_repeat
	
	Qlist_repeat 的要求：
	（0）Quest会指向另外的一个NPC
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
	([
		"quest":	"送花",
		"long":		"天机老人说：飘香花店的老板正缺人手送花，你去帮帮他的忙吧。",
		"short":	"替飘香花店的老板送花",
		"owner":	"huaman",		
		"location":	"飘香花店",		
		"duration":		900,			
		"difficulty":	0,			
		"exp_l":		10,						
		"exp_h":		200,					
		"quest_type":	"special",		
	]),	
	([
		"quest":	"送花",
		"long":		"天机老人说：沉香镇花姑正缺人手送花，你去帮帮她的忙吧。",
		"short":	"替沉香镇的花姑送花",
		"owner":	"huagu",		
		"location":	"沉香镇",		
		"duration":		900,			
		"difficulty":	0,			
		"exp_l":		15,						
		"exp_h":		200,					
		"quest_type":	"special",		
	]),
	([
		"quest":	"绘地图",
		"long":		"天机老人说：警世书局的徐万里需要各地的风土人情，你去看看有什么可以做的。",
		"short":	"替徐万里绘制各地的地图",
		"owner":	"xu wanli",		
		"location":	"风云城",		
		"duration":	900,			
		"difficulty":	200,			
		"exp_l":		20,						
		"exp_h":		200,					
		"quest_type":	"special",		
	]),
	([
		"quest":	"勘探水质",
		"long":		"天机老人说：眉峰聚的陆老板正为他的茶水"YEL"水质"CYN"发愁，你去看看吧。"NOR,
		"short":	"去陆羽处打听水质的事儿",
		"owner":	"lu yu",		
		"location":	"风云城",		
		"duration":		900,			
		"difficulty":	100,			
		"exp_l":		10,						
		"exp_h":		100,					
		"quest_type":	"special",		
	]),
	([
		"quest":	"寻找失物",		// this quest "明霞渡世"
		"long":		"天机老人说：送信的王风前阵子丢了点东西，你过去帮他"YEL"找找"CYN"吧。"NOR,
		"short":	"到风云驿站寻找失物",
		"owner":	"officer wang",		
		"location":	"风云城",		
		"duration":		600,			// here we need a mark for the quest. you may change it later.	
		"difficulty":	0,		
		"cancel": 		100,	// CC +100% 
		"exp_l":		500,						
		"exp_h":		10000,							
		"quest_type":	"special",		
	]),
	([
		"quest":	"桃花林打猎",		
		"long":		"天机老人说：听说武当山下田里的老农正有『难题』，去看看怎么回事儿。",
		"short":	"去武当老农处解决难题",
		"owner":		"farmer",		
		"location":		"武当",		
		"duration":		401,	
		"difficulty":	0,		
		"cancel": 		100,	// CC +100% 
		"exp_l":		200,						
		"exp_h":		350,					
		"quest_type":	"special",		
	]),	
	([
		"quest":	"桃花林狩猎",		
		"long":		"天机老人说：听说武当山下田里的老农正有『难题』，去看看怎么回事儿。",
		"short":	"去武当老农处解决难题",
		"owner":		"farmer",		
		"location":		"武当",		
		"duration":		402,	
		"difficulty":	50,		
		"cancel": 		100,	// CC +100% 
		"exp_l":		350,						
		"exp_h":		500,					
		"quest_type":	"special",		
	]),
	([
		"quest":	"送花",
		"long":		"天机老人说：飘香花店的老板正缺人手送花，你去帮帮他的忙吧。",
		"short":	"替飘香花店的老板送花",
		"owner":	"huaman",		
		"location":	"飘香花店",		
		"duration":		1200,			
		"cancel": 		100,
		"difficulty":	0,			
		"exp_l":		500,						
		"exp_h":		650,					
		"quest_type":	"special",		
	]),	
	([
		"quest":	"送花",
		"long":		"天机老人说：沉香镇花姑正缺人手送花，你去帮帮她的忙吧。",
		"short":	"替沉香镇的花姑送花",
		"owner":	"huagu",		
		"location":	"沉香镇",		
		"duration":		1200,
		"cancel": 		100,			
		"difficulty":	0,			
		"exp_l":		500,						
		"exp_h":		650,					
		"quest_type":	"special",		
	]),
	([
		"quest":	"宣武堂探秘",		
		"long":		"天机老人悄悄地对你说：山水阁钟旒秀正在『招人』，你知道么？",
		"short":	"去钟旒秀处打听招人的事儿",
		"owner":		"zhong",		
		"location":		"风云城",		
		"duration":		411,	
		"difficulty":	0,		
		"cancel": 		100,	// CC +100% 
		"exp_l":		600,						
		"exp_h":		750,					
		"quest_type":	"special",		
	]),
	([
		"quest":	"宣武堂探秘",		
		"long":		"天机老人悄悄地对你说：山水阁钟旒秀正在『招人』，你知道么？",
		"short":	"去钟旒秀处打听招人的事儿",
		"owner":		"zhong",		
		"location":		"风云城",		
		"duration":		412,	
		"difficulty":	50,		
		"cancel": 		100,	// CC +100% 
		"exp_l":		800,						
		"exp_h":		1000,					
		"quest_type":	"special",		
	]),	
	([
		"quest":	"杀一穷二白",		// this quest "明霞渡世"
		"long":		"天机老人说：你不妨去白云行馆，看看最近有什么"YEL"差事"NOR"。",
		"short":	"去白云行馆打听差事",
		"owner":	"princess",		
		"location":	"风云城",		
		"duration":	962,			// here we need a mark for the quest. you may change it later.	
		"difficulty":	0,		
		"cancel": 100,	// CC +100% 
		"exp_l":		900,						
		"exp_h":		1400,					
		"quest_type":	"special",		
	]),	
	([
		"quest":	"三清除妖",		
		"long":		"天机老人说：三清宫丁天师正为练妖之事『烦恼』，你去走一趟？",
		"short":	"去丁乘风处打听烦恼的事儿",
		"owner":		"ding",		
		"location":		"三清宫",		
		"duration":		421,	
		"difficulty":	0,		
		"cancel": 		100,	// CC +100% 
		"exp_l":		1000,						
		"exp_h":		1200,					
		"quest_type":	"special",		
	]),	
	([
		"quest":	"三清除妖",		
		"long":		"天机老人说：三清宫丁天师正为练妖之事『烦恼』，你去走一趟？",
		"short":	"去丁乘风处打听烦恼的事儿",
		"owner":		"ding",		
		"location":		"三清宫",		
		"duration":		422,	
		"difficulty":	0,		
		"cancel": 		100,	// CC +100% 
		"exp_l":		1400,						
		"exp_h":		1800,					
		"quest_type":	"special",		
	]),	
	([
		"quest":	"杀雪域阴魂",		// this quest "明霞渡世"
		"long":		"天机老人说：你不妨去白云行馆，看看最近有什么"YEL"差事"NOR"。",
		"short":	"去白云行馆打听差事",
		"owner":	"princess",		
		"location":	"风云城",		
		"duration":	963,			// here we need a mark for the quest. you may change it later.	
		"difficulty":	0,		
		"cancel": 100,	// CC +100% 
		"exp_l":		1800,						
		"exp_h":		2400,					
		"quest_type":	"special",		
	]),
	([
		"quest":	"地牢探秘",		
		"long":		"天机老人悄悄地对你说：山水阁钟旒秀正在『招人』，你知道么？",
		"short":	"去钟旒秀处打听招人的事儿",
		"owner":		"zhong",		
		"location":		"风云城",		
		"duration":		431,	
		"difficulty":	0,		
		"cancel": 		100,	// CC +100% 
		"exp_l":		2300,						
		"exp_h":		2600,					
		"quest_type":	"special",		
	]),	
		([
		"quest":	"地牢探秘",		
		"long":		"天机老人悄悄地对你说：山水阁钟旒秀正在『招人』，你知道么？",
		"short":	"去钟旒秀处打听招人的事儿",
		"owner":		"zhong",		
		"location":		"风云城",		
		"duration":		432,	
		"difficulty":	50,		
		"cancel": 		100,	// CC +100% 
		"exp_l":		2500,						
		"exp_h":		2800,					
		"quest_type":	"special",		
	]),	
	([
		"quest":	"杀雾影奇邪",		// this quest "明霞渡世"
		"long":		"天机老人说：你不妨去白云行馆，看看最近有什么"YEL"差事"NOR"。",
		"short":	"去白云行馆打听差事",
		"owner":	"princess",		
		"location":	"风云城",		
		"duration":	964,			// here we need a mark for the quest. you may change it later.	
		"difficulty":	0,		
		"cancel": 100,	// CC +100% 
		"exp_l":		3200,						
		"exp_h":		3800,					
		"quest_type":	"special",		
	]),
	([
		"quest":	"地牢探秘",		
		"long":		"天机老人悄悄地对你说：山水阁钟旒秀正在『招人』，你知道么？",
		"short":	"去钟旒秀处打听招人的事儿",
		"owner":		"zhong",		
		"location":		"风云城",		
		"duration":		433,	
		"difficulty":	100,		
		"cancel": 		100,	// CC +100% 
		"exp_l":		3700,						
		"exp_h":		4200,					
		"quest_type":	"special",		
	]),	
	([
		"quest":	"血洗少林",		
		"long":		"天机老人说：上官金虹派人来『招募』,你去敷衍敷衍。",
		"short":	"去上官金虹打听招募的事儿",
		"owner":		"shangguan",		
		"location":		"风云城",		
		"duration":		441,	
		"difficulty":	0,		
		"cancel": 		100,	// CC +100% 
		"exp_l":		4300,						
		"exp_h":		4700,					
		"quest_type":	"special",		
	]),	
	([
		"quest":	"血洗少林",		
		"long":		"天机老人说：上官金虹派人来『招募』,你去敷衍敷衍。",
		"short":	"去上官金虹打听招募的事儿",
		"owner":		"shangguan",		
		"location":		"风云城",		
		"duration":		442,	
		"difficulty":	50,		
		"cancel": 		100,	// CC +100% 
		"exp_l":		4700,						
		"exp_h":		5200,					
		"quest_type":	"special",		
	]),	
	([
		"quest":	"胖胖上香",
		"long":		"天机老人说：边城的胖子金盆洗手，但还是受仇人追杀，你去帮帮他吧。",
		"short":	"去边城找胖子打听一下有什么可帮忙的",
		"owner":	"fatman",		
		"location":	"边城",		
		"duration":		1800,			
		"cancel": 200,	// CC +200% 
		"difficulty":	100,			
		"exp_l":		5000,						
		"exp_h":		10000,					
		"quest_type":	"special",		
	]),
/*	([
		"quest":	"攻打李家庄",
		"long":		"天机老人说：太平镇的武三爷正在找人帮忙，去看看是怎么回事儿。",
		"short":	"去太平镇找武三爷打听一下有什么可帮忙的",
		"owner":	"sanye",		
		"location":	"太平镇",		
		"duration":		1800,			
//		"cancel": 200,	// CC +200% 
		"difficulty":	200,			
		"exp_l":		6000,						
		"exp_h":		10000,					
		"quest_type":	"special",		
	]),
	([
		"quest":	"私人迷宫",
		"long":		"天机老人说：听闻最近有神秘组织频繁活动，你不妨去找城隍庙的和尚打听打听。",
		"short":	"去城隍庙找垂笠老僧打听神秘组织的情形",
		"owner":	"monk",		
		"location":	"城隍庙",		
		"duration":	1260,			
//		"cancel": 200,	// CC +200% 
		"difficulty":	400,			
		"exp_l":		6000,						
		"exp_h":		10000,					
		"quest_type":	"special",		
	]),*/
	([
		"quest":	"瞎子平七",
		"long":		"天机老人说：东边的瞎子平七正在找人帮手，鬼鬼祟祟的也不知在做啥，你且去看上一看。",
		"short":	"到明霞山给瞎子平七打打下手",
		"owner":	"ping qi",		
		"location":	"明霞山",		
		"duration":	600,
		"cancel": 200,	// CC +200% 
		"difficulty":	100,		// reward change in code
		"exp_l":		4000,						
		"exp_h":		10000,					
		"quest_type":	"special",		
	]),	
/*	([
		"quest":	"垂暮老人",
		"long":		"天机老人说：去明霞山听垂暮老人讲一场当年的故事，休息休息罢。",
		"short":	"到明霞山听垂暮老人讲一场当年的故事",
		"owner":	"oldman",		
		"location":	"明霞山",		
		"duration":	600,
		"cancel": 	200,	// CC +200% 
		"difficulty":	440,			
		"exp_l":		3500,						
		"exp_h":		10000,					
		"quest_type":	"special",		
	]),*/

	([
		"quest":	"杀山阴之鬼",		// this quest "万岳峰回"
		"long":		"天机老人说：你不妨去白云行馆，看看最近有什么"YEL"差事"NOR"。",
		"short":	"去白云行馆打听差事",
		"owner":	"princess",		
		"location":	"风云城",		
		"duration":		961,			// here we need a mark for the quest. you may change it later.	
		"difficulty":	0,		
		"cancel": 		100,	// CC +100% 
		"exp_l":		6500,						
		"exp_h":		8000,					
		"quest_type":	"special",		
	]),
	([
		"quest":	"收获的季节",
		"long":		"天机老人说：桃源的郭大妈最近似乎正在为卖不出去的南瓜头痛，你去看看究竟是什么原因。",
		"short":	"到桃源解除郭大妈的烦恼",
		"owner":	"guo dama",		
		"location":	"桃源",		
		"duration":		900,			
		"cancel": 200,	// CC +200% 
		"difficulty":	200,			
		"exp_l":		3000,						
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