

#include "stdafx.h"

#include <EReader.h>

#include "AutoTradingApp.h"
#include "InfoOutputUtil.h"

#ifdef  assert
#undef assert
#include <cassert>
#endif //  assert

#include <boost/lexical_cast.hpp>


AutoTradingApp::AutoTradingApp():
	m_eClientSocket(this,&m_eReaderOSSignal),
	m_pReader(new EReader(&m_eClientSocket,&m_eReaderOSSignal))
{}

bool AutoTradingApp::Initialize(InfoOutputUtil::EOutputType outputType)
{
	return InitializeInfoOutputUtilInst(outputType);
}

void AutoTradingApp::Uninitialize()
{
	UninitializeInfoOutputUtilInst();
}

bool AutoTradingApp::run()
{
	PrintInfo("Connect to 127.0.0.1, port 7497");

	/// 127.0.0.1 is localhost. 7497 is listening port on TWS
	bool res = m_eClientSocket.eConnect("127.0.0.1", 7497, 0);
	if (!res)	return res;

	assert(m_pReader.get() != nullptr);

	///start the msg listenning thread to get data from TWS
	m_pReader->start();

	m_eClientSocket.reqMatchingSymbols(11001, "XLF");

	while (true);

	return true;
}

void AutoTradingApp::tickPrice(TickerId tickerId, TickType field, double price, const TickAttrib& attrib)
{}

void AutoTradingApp::tickSize(TickerId tickerId, TickType field, int size) 
{}

void AutoTradingApp::tickOptionComputation(TickerId tickerId, TickType tickType, double impliedVol, double delta,
	double optPrice, double pvDividend, double gamma, double vega, double theta, double undPrice)
{}

void AutoTradingApp::tickGeneric(TickerId tickerId, TickType tickType, double value)
{}

void AutoTradingApp::tickString(TickerId tickerId, TickType tickType, const std::string& value)
{}

void AutoTradingApp::tickEFP(TickerId tickerId, TickType tickType, double basisPoints, const std::string& formattedBasisPoints,
	double totalDividends, int holdDays, const std::string& futureLastTradeDate, double dividendImpact, double dividendsToLastTradeDate)
{}

void AutoTradingApp::orderStatus(OrderId orderId, const std::string& status, double filled,
	double remaining, double avgFillPrice, int permId, int parentId,
	double lastFillPrice, int clientId, const std::string& whyHeld, double mktCapPrice)
{}

void AutoTradingApp::openOrder(OrderId orderId, const Contract&, const Order&, const OrderState&)
{}

void AutoTradingApp::openOrderEnd()
{}

void AutoTradingApp::winError(const std::string& str, int lastError)
{}

void AutoTradingApp::connectionClosed()
{}

void AutoTradingApp::updateAccountValue(const std::string& key, const std::string& val,
	const std::string& currency, const std::string& accountName)
{}

void AutoTradingApp::updatePortfolio(const Contract& contract, double position,
	double marketPrice, double marketValue, double averageCost,
	double unrealizedPNL, double realizedPNL, const std::string& accountName)
{}

void AutoTradingApp::updateAccountTime(const std::string& timeStamp)
{}

void AutoTradingApp::accountDownloadEnd(const std::string& accountName)
{}

void AutoTradingApp::nextValidId(OrderId orderId)
{
	std::string oderIdString("Next Valid Id:");
	oderIdString.append(boost::lexical_cast<std::string>(orderId));

	PrintInfo(oderIdString);
}

void AutoTradingApp::contractDetails(int reqId, const ContractDetails& contractDetails)
{}

void AutoTradingApp::bondContractDetails(int reqId, const ContractDetails& contractDetails)
{}

void AutoTradingApp::contractDetailsEnd(int reqId)
{}

void AutoTradingApp::execDetails(int reqId, const Contract& contract, const Execution& execution)
{}

void AutoTradingApp::execDetailsEnd(int reqId)
{}

void AutoTradingApp::error(const int id, const int errorCode, const std::string errorString)
{
	std::string errorMsg;
	errorMsg += "TWS Id:";
	errorMsg += boost::lexical_cast<std::string>(id);
	errorMsg += "\t";

	errorMsg += "TWS error code:";
	errorMsg += boost::lexical_cast<std::string>(errorCode);
	errorMsg += "\t";

	errorMsg += errorString;

	PrintError(errorMsg);
}

void AutoTradingApp::updateMktDepth(TickerId id, int position, int operation, int side,
	double price, int size)
{}

void AutoTradingApp::updateMktDepthL2(TickerId id, int position, std::string marketMaker, int operation,
	int side, double price, int size)
{}

void AutoTradingApp::updateNewsBulletin(int msgId, int msgType, const std::string& newsMessage, const std::string& originExch)
{}

void AutoTradingApp::managedAccounts(const std::string& accountsList)
{}

void AutoTradingApp::receiveFA(faDataType pFaDataType, const std::string& cxml)
{}

void AutoTradingApp::historicalData(TickerId reqId, Bar bar)
{}

void AutoTradingApp::historicalDataEnd(int reqId, std::string startDateStr, std::string endDateStr)
{}

void AutoTradingApp::scannerParameters(const std::string& xml)
{}

void AutoTradingApp::scannerData(int reqId, int rank, const ContractDetails& contractDetails,
	const std::string& distance, const std::string& benchmark, const std::string& projection,
	const std::string& legsStr)
{}

void AutoTradingApp::scannerDataEnd(int reqId)
{}

void AutoTradingApp::realtimeBar(TickerId reqId, long time, double open, double high, double low, double close,
	long volume, double wap, int count)
{}

void AutoTradingApp::currentTime(long time)
{}

void AutoTradingApp::fundamentalData(TickerId reqId, const std::string& data)
{}

void AutoTradingApp::deltaNeutralValidation(int reqId, const UnderComp& underComp)
{}

void AutoTradingApp::tickSnapshotEnd(int reqId)
{}

void AutoTradingApp::marketDataType(TickerId reqId, int marketDataType)
{}

void AutoTradingApp::commissionReport(const CommissionReport& commissionReport)
{}

void AutoTradingApp::position(const std::string& account, const Contract& contract, double position, double avgCost)
{}

void AutoTradingApp::positionEnd()
{}

void AutoTradingApp::accountSummary(int reqId, const std::string& account, const std::string& tag, const std::string& value, const std::string& curency)
{}

void AutoTradingApp::accountSummaryEnd(int reqId)
{}

void AutoTradingApp::verifyMessageAPI(const std::string& apiData)
{}

void AutoTradingApp::verifyCompleted(bool isSuccessful, const std::string& errorText)
{}

void AutoTradingApp::displayGroupList(int reqId, const std::string& groups)
{}

void AutoTradingApp::displayGroupUpdated(int reqId, const std::string& contractInfo)
{}

void AutoTradingApp::verifyAndAuthMessageAPI(const std::string& apiData, const std::string& xyzChallange)
{}

void AutoTradingApp::verifyAndAuthCompleted(bool isSuccessful, const std::string& errorText)
{}

void AutoTradingApp::connectAck()
{
	std::string connectString;
	connectString += "Acknowledge connection to ";
	connectString += m_eClientSocket.host();
	connectString += " Port:";
	connectString += boost::lexical_cast<std::string>(m_eClientSocket.port());

	PrintInfo(connectString);

	//m_eClientSocket.asyncEConnect(true);

	m_eClientSocket.startApi();
}

void AutoTradingApp::positionMulti(int reqId, const std::string& account, const std::string& modelCode, const Contract& contract, double pos, double avgCost)
{}

void AutoTradingApp::positionMultiEnd(int reqId)
{}

void AutoTradingApp::accountUpdateMulti(int reqId, const std::string& account, const std::string& modelCode, const std::string& key, const std::string& value, const std::string& currency)
{}

void AutoTradingApp::accountUpdateMultiEnd(int reqId)
{}

void AutoTradingApp::securityDefinitionOptionalParameter(int reqId, const std::string& exchange, int underlyingConId, const std::string& tradingClass, const std::string& multiplier, std::set<std::string> expirations, std::set<double> strikes)
{}

void AutoTradingApp::securityDefinitionOptionalParameterEnd(int reqId)
{}

void AutoTradingApp::softDollarTiers(int reqId, const std::vector<SoftDollarTier> &tiers)
{}

void AutoTradingApp::familyCodes(const std::vector<FamilyCode> &familyCodes)
{}

void AutoTradingApp::symbolSamples(int reqId, const std::vector<ContractDescription> &contractDescriptions)
{
	if (reqId == 11001)
	{
		int b = 0;
	}
	int a = 0;
}

void AutoTradingApp::mktDepthExchanges(const std::vector<DepthMktDataDescription> &depthMktDataDescriptions)
{}

void AutoTradingApp::tickNews(int tickerId, time_t timeStamp, const std::string& providerCode, const std::string& articleId, const std::string& headline, const std::string& extraData)
{}

void AutoTradingApp::smartComponents(int reqId, SmartComponentsMap theMap)
{}

void AutoTradingApp::tickReqParams(int tickerId, double minTick, std::string bboExchange, int snapshotPermissions)
{}

void AutoTradingApp::newsProviders(const std::vector<NewsProvider> &newsProviders)
{}

void AutoTradingApp::newsArticle(int requestId, int articleType, const std::string& articleText)
{}

void AutoTradingApp::historicalNews(int requestId, const std::string& time, const std::string& providerCode, const std::string& articleId, const std::string& headline)
{}

void AutoTradingApp::historicalNewsEnd(int requestId, bool hasMore)
{}

void AutoTradingApp::headTimestamp(int reqId, const std::string& headTimestamp)
{}

void AutoTradingApp::histogramData(int reqId, HistogramDataVector data)
{}

void AutoTradingApp::historicalDataUpdate(TickerId reqId, Bar bar)
{}

void AutoTradingApp::rerouteMktDataReq(int reqId, int conid, const std::string& exchange)
{}

void AutoTradingApp::rerouteMktDepthReq(int reqId, int conid, const std::string& exchange)
{}

void AutoTradingApp::marketRule(int marketRuleId, const std::vector<PriceIncrement> &priceIncrements)
{}

void AutoTradingApp::pnl(int reqId, double dailyPnL, double unrealizedPnL, double realizedPnL)
{}

void AutoTradingApp::pnlSingle(int reqId, int pos, double dailyPnL, double unrealizedPnL, double realizedPnL, double value)
{}

void AutoTradingApp::historicalTicks(int reqId, const std::vector<HistoricalTick> &ticks, bool done)
{}

void AutoTradingApp::historicalTicksBidAsk(int reqId, const std::vector<HistoricalTickBidAsk> &ticks, bool done)
{}

void AutoTradingApp::historicalTicksLast(int reqId, const std::vector<HistoricalTickLast> &ticks, bool done)
{}


AutoTradingApp::Scope::Scope(IAppControl *appControl):
	m_appControl(appControl)
{
}

AutoTradingApp::Scope::~Scope()
{
	if (m_appControl)	m_appControl->Uninitialize();
}