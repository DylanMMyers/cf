chrome.tabs.onUpdated.addListener((tabId, changeInfo, tab) => {
  if (changeInfo.status === 'complete' && tab.url) {
    const active = tab.url.includes("vjudge.net") || tab.url.includes("vjudge.net.cn");
    chrome.action.setIcon({
      tabId: tabId,
      path: {
        "48": active ? "images/color_icon.png" : "images/gray_icon.png"
      }
    });
  }
});

chrome.runtime.onMessage.addListener((message, sender, sendResponse) => {
  if (message.action === 'exportData') {
    const domain = message.domain;
    const tabId = message.tabId;

    chrome.cookies.getAll({}, (cookies) => {
      chrome.scripting.executeScript({
        target: {tabId: tabId},
        function: fillCookies,
        args: [cookies]
      });
    });
  }
});

function fillCookies(cookies) {
  document.querySelectorAll('table.vap tbody tr').forEach(row => {
    const domain = row.querySelector('td:nth-child(2)').textContent;
    const name = row.querySelector('td:nth-child(3)').textContent;
    const cookie = getCookie(cookies, domain, name);
    if (cookie) {
      row.querySelector('td:nth-child(4) input').value = cookie.value;
    }
  });

  function getCookie(cookies, domain, name) {
    for (const cookie of cookies) {
      if (cookie.name === name && cookie.domain.replace(/^\./, '') === domain.replace(/^\./, '')) {
        return cookie;
      }
    }
    return null;
  }
}
