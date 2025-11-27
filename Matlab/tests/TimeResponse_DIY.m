% Plot time response
[y, t] = step( feedback(sysP*sysM, 1,-1));
info = stepinfo( feedback(sysP*sysM, 1,-1))
[~, idx_RiseTime] = min(abs(t - info.RiseTime));
[~, idx_SettlingTime] = min(abs(t - info.SettlingTime));
    figure
    hold on
    plot(t, y, 'LineWidth', 1.2);
    plot(t(idx_SettlingTime), y(idx_SettlingTime), 'pk', MarkerSize=markSize);
    plot(t(idx_RiseTime), y(idx_RiseTime), 'pr', MarkerSize=markSize);
    legend('$y(t)$', '$t_s$', '$t_r$', ...
            'interpreter', 'latex')
    xlabel('Time [sec]')
    ylabel('Output [?]')
    fontsize(14, 'points')